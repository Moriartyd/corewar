.name       ""
.comment ""
zjmp:
	or  
	and%:zjmp, r2, r3
live:
	live %0 , r3               # <-- На эту операцию указывает метка live
	ld %0           # <-- А на эту операцию никакая метка не указывает
	zjmp %:zjmp
