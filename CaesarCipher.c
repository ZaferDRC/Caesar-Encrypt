#include <stdio.h>
#include <string.h>

void CaesarEncrypt(char str[], int key)
{
	int i;
	char cipherStr[100];
	
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
	
	cipherStr[i] = '\0';
	
	printf("Encrypt Text: %s\n",cipherStr);
	
}

void CaesarDecode(char cipherStr[], int key)
{
	
	int i;
	char decodedStr[100];
	
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
	
	
    printf("Decoded Text: %s\n", decodedStr);

}

int main()
{
	char txt[100];
	int key,choose;
	
	while (1)
	{
		
		printf("1-Encrypt Caesar\n");
		printf("2-Decrypt Caesar\n");
		printf("3-Clean The Terminal\n");
		printf("4-Close The Program\n\n");
		printf("Please Make Your Choice\n");
		scanf("%d",&choose);
		
		if (choose < 1 || choose > 4)
		{
    		printf("Your Choice Must Be Between 1-4 !!\n");
    		break;
		}

		
		switch(choose)
		{
			case 1:
				
				printf("Please Enter The Text To Be Encrypted:\n");
				scanf("%s",&txt);
	
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
				
				break;
			
			case 2:
				
				printf("Please Enter The Text To Be Decrypted:\n");
				scanf("%s",txt);
			
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
        		
				break;
				        	
        	case 3:
        		
        		system("cls");
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
