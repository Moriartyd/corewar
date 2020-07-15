.name       ""
.comment ""
loop:
	or %:live, %:live, r2    # <-- На эту операцию указывает метка loop
	and%:loop, r2, r3
live:
	live %0               # <-- На эту операцию указывает метка live
	ld %0, r2             # <-- А на эту операцию никакая метка не указывает
	zjmp %:loop
