import os
import sys

def day1_part1(content_list):
	for i in content_list:
		for j in content_list[1:]:
			if int(i) + int(j) == 2020:
				return int(i) * int(j)		

def day1_part2(content_list):
	for i in content_list:
		for j in content_list[1:]:
			for k in content_list[2:]:
				if int(i) + int(j) + int(k) == 2020:
					return int(i) * int(j) * int(k)

if __name__ == "__main__":
	
	text_list = open("day1_input.text", "r")
	content = text_list.read()
	content_list = content.split("\n")
	text_list.close()
	del content_list[-1]
	
	print(day1_part1(content_list))
	print(day1_part2(content_list))
	
	
