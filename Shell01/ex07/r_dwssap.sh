cat /etc/passwd | sed /^#/d | sed -n 'n;p' | awk -F: '{print $1}'| rev | sort -r | sed -n ''$FT_LINE1','$FT_LINE2'p' | sed -n 'H;${x;s/\n/, /g;s/^, //;p;}' | sed 's/$/./' | tr -d '\n'
