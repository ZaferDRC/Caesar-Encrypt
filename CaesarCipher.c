#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // Constant Definition

// Encryption Function

void CaesarEncrypt(char str[], int key)
{
	int i;
	char cipherStr[MAX_LENGTH];
	
	for(i = 0; i < strlen(str); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			cipherStr[i] = 'A' + (str[i] - 'A' + key) % 26;
		}
		
		else if(str[i] >= 'a' && str[i] <= 'z')
		{
			cipherStr[i] = 'a' + (str[i] - 'a' + key) % 26;
		}
		
		else
		{
			printf("Please Enter Letters Only!");
			break;
		}
	}
	
	cipherStr[i] = '\0';  // We Use It, Because Array Is Finished.
	
	printf("Encrypt Text: %s\n\n",cipherStr);
	
}

// Decryption Function

void CaesarDecode(char cipherStr[], int key)
{
	
	int i;
	char decodedStr[MAX_LENGTH];
	
	for(i = 0; i < strlen(cipherStr); i++)
	{
		
		if(cipherStr[i] >= 'A' && cipherStr[i] <= 'Z')
		{
			decodedStr[i] = 'A' + (cipherStr[i] - 'A' - key + 26) % 26;
		}
		
		else if(cipherStr[i] >= 'a' && cipherStr[i] <= 'z')
		{
			decodedStr[i] = 'a' + (cipherStr[i] - 'a' - key + 26) % 26;
		}
		
		else
		{
			printf("Please Enter Letters Only!");
			break;
		}
	}
	
	decodedStr[i] = '\0';
	
	
    printf("Decoded Text: %s\n\n", decodedStr);

}

int main()
{
	
	char txt[MAX_LENGTH];
	char temp[MAX_LENGTH];
	int i,key,choose,validInput = 1;
	
	while (1)
	{
		
		printf("1-Encrypt Caesar\n");
		printf("**********************\n");		
		printf("2-Decrypt Caesar\n");
		printf("**********************\n");
		printf("3-Clean The Terminal\n");
		printf("**********************\n");
		printf("4-Close The Program\n");
		printf("**********************\n\n");
		printf("Please Make Your Choice\n");
		scanf("%d",&choose);
		
		if (choose < 1 || choose > 4)
		{
    		printf("Your Choice Must Be Between 1-4 !!\n");
    		break;
		}

		getchar(); // We Use It To Clear The Remaining Data From Scanf.
		
		switch(choose)
		{
			case 1:
				
				printf("Please Enter The Text To Be Encrypted:\n");
				fgets(temp, sizeof(temp), stdin); // Parameter Order: 1- Where Will The Data Be Transferred? 2- How Much Data Will Be Taken ? 3- Where To Get Data ?
				temp[MAX_LENGTH - 1] = '\0';     // We Indicate That The Data Is Finished By Placing A Null Character At The End Of The Array.
				     
				if(strlen(temp) >= MAX_LENGTH - 1)
				{
					printf("You Can Enter A Maximum Of 100 Characters!");
					return 0;
				}
								
				for(i = 0; temp[i] != '\0'; i++)
				{
					if(!isalpha(temp[i]) && temp[i] != '\n' && temp[i] != '\r')
					{
						printf("Please Enter Only Letters!\n");
						validInput = 0;
						return 0;
					}
				}
				
				if(validInput)
				{
					sscanf(temp,"%s",txt);
					printf("Please Enter The Encryption Key (Between 0-25)\n");
					scanf("%d",&key);
			
					if(key < 0 || key > 25)
					{
						printf("Encryption Key Must Be Between 0-25 !!\n");
					}
			
					else
					{
						CaesarEncrypt(txt,key);
					}
				}
				
				getchar();
				break;
			
			case 2:
				
				printf("Please Enter The Text To Be Decrypted:\n");
				fgets(temp, sizeof(temp),stdin);
				temp[MAX_LENGTH - 1] = '\0'; 
				
				if(strlen(temp) >= MAX_LENGTH - 1 )
				{
					printf("You Can Enter A Maximum Of 100 Characters!");
					return 0;
				}
				
				for(i = 0; i < temp[i] != '\0'; i++)
				{
					if(!isalpha(temp[i]) && temp[i] != '\n' && temp[i] != '\r')
					{
						printf("Please Enter Only Letters!\n");
						validInput = 0;
						return 0;
					}
				}
				
				if(validInput)
				{
					sscanf(temp , "%s" , txt);
					printf("Please Enter The Decryption Key (Between 0-25)\n");
        			scanf("%d", &key);
        		
        			if(key < 0 || key > 25)
        			{
        				printf("Decryption Key Must Be Between 0-25 !!\n");
					}
				
					else
					{
						CaesarDecode(txt, key);
					}
				}
        		
        		getchar();
				break;
				        	
        	case 3:
        		
        		system("cls"); // This Command Is Clear The Screen.
        		break;
        		
        	case 4:
        		
        		printf("Program Is Closing...\n");
				return 0;
				break;
				
			default:
				
				printf("Invalid choice. Please choose a valid option.\n");
				break;
				
		}

	}
	
	return 0;
	
}
