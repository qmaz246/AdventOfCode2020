import os
import sys
from collections import Counter 

def day2_part1(content_list):
	
	valid_passwords = 0
	
	for i in content_list:
		min_num = int(i.split("-")[0])
		max_num = int(i.split("-")[1].split(" ")[0])
		letter = i.split("-")[1].split(" ")[1].split(":")[0]
		password = i.split("-")[1].split(" ")[2]
		count = Counter(password)[letter]
		if min_num <= count and max_num >= count:
			valid_passwords += 1
				
	return valid_passwords


def day2_part2(content_list):
	valid_passwords = 0
	valid = 0
	for i in content_list:
		pos1 = int(i.split("-")[0])-1 # starts at 1 not 0
		pos2 = int(i.split("-")[1].split(" ")[0])-1
		letter = i.split("-")[1].split(" ")[1].split(":")[0]
		password = i.split("-")[1].split(" ")[2]
		
		if password[pos1] == letter:
			valid += 1
			
		if len(password) > pos2:
			print(password[pos1], password[pos2])
			if password[pos2] == letter:
				valid += 1
		else:
			print(password[pos1], ' ')
			
		if valid == 1:
			valid_passwords += 1
			
			
		valid = 0
		print valid_passwords
	return valid_passwords
	
if __name__ == "__main__":
	
	text_list = open("Day2_input.txt", "r")
	content = text_list.read()
	content_list = content.split("\n")
	text_list.close()
	del content_list[-1]
	
	print(day2_part1(content_list))
	print(day2_part2(content_list))
