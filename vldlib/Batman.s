.name       ""
.comment ""
zjmp:
	and :zjmp, r0, r3
live:
	live %0               # <-- На эту операцию указывает метка live
	          # <-- А на эту операцию никакая метка не указывает
	zjmp %:zjmp
	sti r1,-2, %1#dsad
