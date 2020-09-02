//Grant Haataja - Hw 1

#include <stdlib.h>

int main() 
{
	//first make the system call to wget
	system("wget -q http://www.senate.gov/general/contact_information/senators_cfm.cfm");
	
	//next display the web addresses on the screen
	system("grep -Eoi '<a [^>]+>' senators_cfm.cfm | grep -Eo 'href=\"[^\\\"]+\"' | grep -Eo '(http|https):\/\/[^\"]+' ");
	
	//finally unlink the downloaded file
	system("unlink senators_cfm.cfm");
}
