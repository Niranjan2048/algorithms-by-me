#                         EXPERIMENT-5a
#NAME:NIRANJAN MANGESH KHEDKAR
#ROLL NO:CEB429
#Batch: B1
#AIm::  Write a program to demonstrate use of packages and
#module using data structure  stack 
from DS.stackds import stack

s = stack()
text = input("Please enter the string :")

for character in text:
    s.push(character)

reverse = ""
while not s.is_empty():
    reverse = reverse + s.pop()

if text == reverse:
    print("The string is a palindrome")

else:
    print("The string is not a palindrome")
