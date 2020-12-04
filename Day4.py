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
    for i in content_list:
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
        
        for j in list:
            ky = j.split(":")[0]
            val = j.split(":")[1]
            if(ky=="byr"):
                vals = int(val)
                if vals < 1920 or vals > 2002:
                    valid_pass = 0
            
            if(ky=="iyr"):
                vals = int(val)
                if vals < 2010 or vals > 2020:
                    valid_pass = 0
            
            if(ky=="eyr"):
                vals = int(val)
                if vals < 2020 or vals > 2030:
                    valid_pass = 0
            
            if(ky=="hgt"):
                if "cm" in val:
                    height = int(val[:-2])
                    if height < 150 or height > 193:
                        valid_pass = 0
                elif "in" in val:
                    height = int(val[:-2])
                    if height < 59 or height > 76:
                        valid_pass = 0
                else:
                    valid_pass = 0
            
            if(ky=="hcl"):
                if not re.search("^#[0-9a-f]{6}", val):
                    valid_pass = 0

            if(ky=="ecl"):
                if val not in ["amb","blu","brn","gry","grn","hzl","oth"]:
                    valid_pass = 0
            
            if(ky=="pid"):
                if not re.search("[0-9]{9}", val):
                    valid_pass = 0            

        if valid_pass == 1:
            valid += 1
            print(list)
        #print(list, len(list), valid)
    return valid

if __name__ == "__main__":
    text_list = open("Day4_input.txt", "r")
    content = text_list.read()
    content_list = content.split("\n\n")
    text_list.close()
    print(day4_part1(content_list))

    print(day4_part2(content_list))