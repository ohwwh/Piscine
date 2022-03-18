echo "ibase=5; $FT_NBR1+$FT_NBR2" | tr $'\'\\' '01' | tr '\"\?\!' '234' | tr 'mrdoc' '01234' | sed 's/iba/obase=13; iba/' | bc | tr '0123456789ABC' 'gtaio luSnemf'
