#!/usr/bin/env bash

#FT_NBR1=\\\"\\\"!\\\"\\\"!\\\"\\\"!\\\"\\\"!\\\"\\\"!\\\"\\\"
#FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo
#FT_NBR1=\\\'\?\"\\\"\'\\
#FT_NBR2=rcrdmddd

NUMS_IN1=''\''\\"?!'
NUMS_IN2='mrdoc'
NUMS_OUT='gtaio luSnemf'

NUMS_NORMAL5='01234'
NUMS_NORMAL13='0123456789ABC'

FT_NBR1=$(echo "$FT_NBR1" | tr "${NUMS_IN1}" "${NUMS_NORMAL5}")
FT_NBR2=$(echo "$FT_NBR2" | tr "${NUMS_IN2}" "${NUMS_NORMAL5}")

sum_13=$(echo "obase=13; ibase=5; $FT_NBR1 + $FT_NBR2" | bc)

sum_13o=$(echo "$sum_13" | tr "${NUMS_NORMAL13}" "${NUMS_OUT}")

echo "$sum_13o"
