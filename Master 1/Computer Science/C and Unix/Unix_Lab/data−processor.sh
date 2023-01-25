# !/bin/bash

curl -s -L https://bit.ly/2ATet9V | sed '1d' | cut -f 2,3,4 -d "," | sed 's/,/ /' | sed 's/@.*/@****.***/g' 