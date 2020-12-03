import os
import sys

def day3_part1(y):
	# how many trees (#) are encountered right 3 down 1?
	trees = 0
	x_max = len(y[0])
	y_max = len(y)
	
	curr_y = 0
	curr_x = 0
	while(curr_y < y_max):		
		#print(curr_y, curr_x)
		# check location for open space or tree
		if y[curr_y][curr_x] == "#":
			trees += 1
		
		# New Position
		curr_y += 1
		curr_x += 3
		
		# Check for loopback for x
		if curr_x >= x_max:
			curr_x = curr_x - x_max
	
	return trees

def day3_part2(y):
	# how many trees (#) are encountered right 3 down 1?
	trees = 1
	x_max = len(y[0])
	y_max = len(y)
	
	for i in [(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)]:
		curr_y = 0
		curr_x = 0
		trees_thisrun = 0
		while(curr_y < y_max):		
			#print(curr_y, curr_x)
			# check location for open space or tree
			if y[curr_y][curr_x] == "#":
				trees_thisrun += 1
			
			# New Position
			curr_y += i[1]
			curr_x += i[0]
			
			# Check for loopback for x
			if curr_x >= x_max:
				curr_x = curr_x - x_max
		
		trees = trees * trees_thisrun
		print(i[0], i[1], trees_thisrun, trees)
	
	return trees
		
if __name__ == "__main__":
	
	text_list = open("Day3_input.txt", "r")
	content = text_list.read()
	content_list = content.split("\n")
	text_list.close()
	del content_list[-1]

	# convert the list into a 2D array
	y = []
	for i in content_list:
		x = []
		for j in i:
			x.append(j)
		
		y.append(x)

	print(day3_part1(y))

	print(day3_part2(y))
