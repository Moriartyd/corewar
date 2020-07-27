test_asm_invalid() {
	CHAMPS=$(find ./vm_champs/champs/invalid -name '*.s')
	for CHAMP in $CHAMPS; do
		OUTPUT=$(./asm/asm $CHAMP | grep -i 'you\|some\|\[')
		if [ -z $CHAMP ]; then
			printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
			rm -rf ${CHAMP%.s}.cor
		else
			printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
		fi
	done
	$(find ./vm_champs/champs/invalid -name '*.cor' | xargs rm -rf)
}

test_asm_valid() {
	CHAMPS=$(find ./vm_champs/champs/championships ./vm_champs/champs/valid -name '*.s')
	for CHAMP in $CHAMPS; do
		OUTPUT=$(./asm/asm $CHAMP | grep -i 'you\|some\|\[')
		if [[ $OUTPUT ]]; then
			printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
		else
			mv ${CHAMP%.s}.cor tmp.cor
			./vm_champs/asm $CHAMP > /dev/null
			hexdump -Cv tmp.cor > our_tmp
			hexdump -Cv ${CHAMP%.s}.cor > or_tmp
			DIFF=$(diff -U 2 or_tmp our_tmp)
			rm -rf tmp.cor ${CHAMP%.s}.cor or_tmp our_tmp
			if [[ $OUTPUT ]]; then
				printf "%s: \e[1;31mKO\e[0m\n" "$CHAMP"
				echo $DIFF
			else
				printf "%s: \e[1;32mOK\e[0m\n" "$CHAMP"
			fi
		fi
		rm -rf ${CHAMP%.s}.cor
	done
}

if [ $1 = 'valid' ]; then
	make -C ./asm > /dev/null
	test_asm_valid
fi

if [ $1 = 'invalid' ]; then
	make -C ./asm > /dev/null
	test_asm_invalid
fi

if [ $1 = 'all' ]; then
	make -C ./asm > /dev/null
	echo "TESTING VALID CHAMPIONS"
	test_asm_valid
	echo "TESTING IN_VALID CHAMPIONS"
	test_asm_invalid
fi