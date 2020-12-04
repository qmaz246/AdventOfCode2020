import os
import sys
import re

def day4_part1(content_list):
    valid = 0
    for i in content_list:
        list = i.replace("\n", " ").split(" ")
        
        cid_present = 0
        num_fields = len(list)
    
        if num_fields == 9:
            del list[-1]
            num_fields += -1

        if num_fields == 8:
            valid += 1

        elif num_fields == 7:
            for j in list:
                if j.split(":")[0] == "cid":
                    cid_present = 1
            if cid_present == 0:
                valid += 1
        
        #print(list, len(list), valid)
    return valid

def day4_part2(content_list):
    valid = 0
    print(len(content_list))

    for i in content_list:
        if i[-1] == "\n":
			i = i[:-1]
			
        list = i.replace("\n", " ").split(" ")
        
        cid_present = 0
        valid_pass = 0
        num_fields = len(list)
    
        if num_fields == 9:
            del list[-1]
            num_fields += -1

        if num_fields == 8:
            valid_pass = 1

        elif num_fields == 7:
            for j in list:
                if j.split(":")[0] == "cid":
                    cid_present = 1
            if cid_present == 0:
                valid_pass = 1
        
        if valid_pass == 1:
			for j in list:
				split_up = j.split(":")
				ky = split_up[0]
				val = split_up[1]

				if(ky=="byr"):
					if not re.search("(19[2-9][0-9]|200[012])", val):
						valid_pass = 0
				
				if(ky=="iyr"):
					if not re.search("(201[0-9]|2020)", val):
						valid_pass = 0
				
				if(ky=="eyr"):
					if not re.search("(202[0-9]|2030)", val):
						valid_pass = 0
				
				if(ky=="hgt"):
					if not re.search("((1[5678][0-9]|19[0123])cm|(59|6[0-9]|7[0-6])in)", val):
						valid_pass = 0
				
				if(ky=="hcl"):
					if not re.search("#[0-9a-f]{6}( |$)", val):
						valid_pass = 0

				if(ky=="ecl"):
					if not re.search("(amb|blu|brn|gry|grn|hzl|oth)", val):
						valid_pass = 0
				
				if(ky=="pid"):
					if not re.search("[0-9]{9}( |$)", val):
						valid_pass = 0        

        if valid_pass == 1:
            valid += 1
            #print(list, len(list), valid_pass, valid)
    return valid

if __name__ == "__main__":
    text_list = open("Day4_input.txt", "r")
    content = text_list.read()
    content_list = content.split("\n\n")
    text_list.close()
    
    print(day4_part1(content_list))

    print(day4_part2(content_list))
