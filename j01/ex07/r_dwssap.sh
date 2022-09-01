cat /etc/passwd | sed '/^#/d' | sed -n '2~p' | sed 's/:\(.*\)//g' | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | tr '\n' ',' | sed 's/.$//' | sed 's/\(.\)$/\1./'
