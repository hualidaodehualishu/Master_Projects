import cv2 as cv
import numpy as np
import sys

########################TrackBAR#########################

#Make Keypoints
trackKP_name = "Keypoints"
trackKP_max_value = 1  # Trackbar max value
trackKP_value = 0  # Trackbar value
trackKP_default_value = False

#Make Matching
trackMT_name = "Descriptor Matching"
trackMT_max_value = 1  # Trackbar max value
trackMT_value = 0  # Trackbar value
trackMT_default_value = False

#Make Augmentation
trackAG_name = "Augmentation"
trackAG_max_value = 1  # Trackbar max value
trackAG_value = 0  # Trackbar value
trackAG_default_value = False

#Control Opacity
trackOP_name = "Opacity Coefficient"
trackOP_max_value = 10  # Trackbar max value
trackOP_value = 5  # Trackbar value
trackOP_default_value = 5
trackbartrackOP_min_value = 0

########################################################

def aug_process():
    if len(good_match) > 4:
        ptsA = np.float32([kp1[m.queryIdx].pt for m in good_match]).reshape(-1, 1, 2)
        ptsB = np.float32([kp2[m.trainIdx].pt for m in good_match]).reshape(-1, 1, 2)
        ransacReprojThreshold = 4
        H, status = cv.findHomography(ptsA, ptsB, cv.RANSAC, ransacReprojThreshold)
        imgOut = cv.warpPerspective(img_1, H, (frame.shape[1], frame.shape[0]))
    return imgOut,H,status

def show_KP():
    outimg2 = cv.drawKeypoints(img_2, keypoints=kp2, outImage=None)
    outimg3 = np.hstack([outimg1, outimg2])
    cv.imshow(window_in_name, outimg3)

def draw_match(img1, img2, kp1, kp2, match):
    outimage = cv.drawMatches(img1, kp1, img2, kp2, match, outImg=None)
    cv.imshow(window_in_name, outimage)

def image1_grab():
    global orb
    global kp1
    global img_1
    global des1
    global outimg1
    img_1 = cv.imread("./images/book.jpeg")
    img_1 = cv.resize(img_1, (1280,720))
    orb = cv.ORB_create()
    kp1 = orb.detect(img_1)
    kp1, des1 = orb.compute(img_1, kp1)
    outimg1 = cv.drawKeypoints(img_1, keypoints=kp1, outImage=None)

def create_GUI():
    global window_in_name, window_out_name, window_settings_name  # Windows
    window_name_prefix = 'OpenCV Demo | Final Project > '
    # Create windows
    window_in_name = window_name_prefix + 'Augmented Reality'
    cv.namedWindow(window_in_name, cv.WINDOW_AUTOSIZE)

    window_settings_name = window_name_prefix + 'Parameters Settings'
    cv.namedWindow(window_settings_name, cv.WINDOW_AUTOSIZE)

    # Create trackbars
    # - For KP
    cv.createTrackbar(trackKP_name, window_settings_name, 0,
                      trackKP_max_value, process_display_callback)

    # - For MT
    cv.createTrackbar(trackMT_name, window_settings_name, 0,
                      trackMT_max_value, process_display_callback)

    # - For Ag
    cv.createTrackbar(trackAG_name, window_settings_name, 0,
                      trackAG_max_value, process_display_callback)

    # - For OP
    cv.createTrackbar(trackOP_name, window_settings_name, 0,
                      trackOP_max_value, process_display_callback)
    cv.setTrackbarMin(trackOP_name, window_settings_name,
                      trackbartrackOP_min_value)

    # Set trackbar default positions
    # - For KP
    trackbarKP_value = trackKP_value
    cv.setTrackbarPos(trackKP_name, window_settings_name,
                      trackbarKP_value)

    # - For MT
    trackbarMT_value = trackMT_value
    cv.setTrackbarPos(trackMT_name, window_settings_name,
                      trackbarMT_value)

    # - For AG
    trackbarAG_value = trackAG_value
    cv.setTrackbarPos(trackAG_name, window_settings_name,
                      trackbarAG_value)

    # - For OP
    trackbarOP_value = trackOP_value
    cv.setTrackbarPos(trackOP_name, window_settings_name,
                      trackbarOP_value)

# Input & Preprocessing
def initialize_stream():
    global cap
    global frame, frame_overlay
    global isGrayCamera
    # Open default camera
    cap = cv.VideoCapture(0)
    image1_grab()
    # Check if camera opening is successful
    if not cap.isOpened():
        sys.exit("! Cannot open default camera")

    # Get camera properties and initialize various variables
    # - Get frame dimensions
    ncols = (int)(cap.get(cv.CAP_PROP_FRAME_WIDTH))
    nrows = (int)(cap.get(cv.CAP_PROP_FRAME_WIDTH))

    # - Check for color camera
    status, frame = cap.read()  # Get frame
    #print(frame)
    if not status:
        sys.exit("! Cannot grab frame from default camera")
    if frame.ndim == 1:
        isGrayCamera = True
    else:
        isGrayCamera = False

    #frame_overlay = np.empty((nrows, ncols, 3), dtype="uint8")

def process_display_callback(value):
    global KP
    global MT
    global AG
    global OP
    trackbarKP_value =  cv.getTrackbarPos(trackKP_name,window_settings_name)
    trackbarMT_value = cv.getTrackbarPos(trackMT_name, window_settings_name)
    trackbarAG_value = cv.getTrackbarPos(trackAG_name, window_settings_name)
    trackbarOP_value = cv.getTrackbarPos(trackOP_name, window_settings_name)

    KP = trackbarKP_value
    MT = trackbarMT_value
    AG = trackbarAG_value
    OP = (float)(trackbarOP_value/10)


def grab_preprocess():
    global frame, the_frame
    # Get a new frame from camera
    status, frame = cap.read()
    # Convert image to graylevel if appropriate
    if isGrayCamera:
        the_frame = frame
    else:
        the_frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

# Processing & Visualization
def process_display():
    global frame_out, frame_overlay,img_2,kp2, good_match
    ########################################## Image descriptor extraction
    img_2 = frame
    kp2 = orb.detect(img_2)
    kp2, des2 = orb.compute(img_2, kp2)
    ##########################################
    ########################################### Descriptor matching & Match filtering
    bf = cv.BFMatcher(cv.NORM_HAMMING)
    matches = bf.match(des1, des2)
    min_distance = matches[0].distance
    max_distance = matches[0].distance
    for x in matches:
        if x.distance < min_distance:
            min_distance = x.distance
        if x.distance > max_distance:
            max_distance = x.distance
    good_match = []
    for x in matches:
        if x.distance <= max(2 * min_distance, 30):
            good_match.append(x)
    ############################################

    ############################################ Show results
    if KP == 1 :
        show_KP()
    elif MT == 1 :
        draw_match(img_1, img_2, kp1, kp2, good_match)
    elif AG == 1 :
        AugImg, H, status = aug_process()
        frame_aug = cv.addWeighted(frame,0.8,AugImg,OP,0)
        cv.imshow(window_in_name,frame_aug)
    else:
        cv.imshow(window_in_name,frame)
    ###########################################

## MAIN ROUTINE
def application():
    # Open camera & Get its features
    initialize_stream()
    # Grab & preprocess frame
    grab_preprocess()
    # GUI creation
    create_GUI()
    # Invoke callback routine to initialize and process
    process_display_callback(trackKP_value)
    # Process video stream
    while True:
        # Grab & preprocess frame
        grab_preprocess()
        # Processing & Visualization
        process_display()
        # Listen to next event
        if cv.waitKey(5) >= 0:
            break
    # Release camera
    cap.release()
    # Destroy windows
    cv.destroyAllWindows()

# Run application
if __name__=="__main__":
    application()
