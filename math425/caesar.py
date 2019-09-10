#Caesar Cipher Program
def encrypt(text, s):
	result = ""
	
	#parse through text
	for i in range(len(text)):
		char = text[i]
		
		#encrypt the text
		if (char.isupper()):
			result += chr((ord(char) + s-65) % 26 + 65)
			
		else:
			result += chr((ord(char) + s - 97) % 26 + 97)
        	
	return result
        
text = "She told me to walk this way"
s = 14
print("Text  : " + text)
print("Shift : " + str(s))
print("Cipher: " + encrypt(text,s))
