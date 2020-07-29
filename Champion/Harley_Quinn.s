.name		"Harley Quinn"
.comment	"I love you soooooo much, Pudding <3"

	ld		%0,r3			# carry -> 1
	ld		%1,r2			# carry -> 0
	sti		r1,%:live,%1
	sti		r1,%:lv,%1
	sti		r1,%:boom,%1
myfork:
	add		r3,r2,r3
	and		r3,%3,r4
lv: live	%2
	zjmp	%:end
	fork	%:myfork
	ld		%0, r4
	zjmp %:myfork
live:
	live	%1
end: ld	%1 r3
boom: live %5
zjmp %:boom
