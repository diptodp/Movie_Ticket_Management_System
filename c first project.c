// This is a simple "Movie Ticket Management" project done by CSE115L.09 SPRING2020 GROUP-E
// I would like to thank my fellow teammates and friends Abrar, Niaz and Pappu and my friend from another group Yaman
// I would also like to thank our faculty Rashed Shelim Topu sir and Mayamin Hamid Raha apu for their support throughout our course

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection();
void reg_info();
void hollywood();
void bollywood();
void tollywood();
void write_movie();
void main_screen();
void read_from_file();
void ticket(int genre, int choice);


struct movie
{
    char m_name[50];
    char time[20];
    char date[20];
    int price;
};


struct member
{
    char username[50];
    char password[50];
    char mobile[15];
    char email[50];

}data[100];


typedef struct movie movie;
typedef struct member member;


void ticket(int genre, int choice);


FILE *file;
FILE *customer;
FILE *number;


movie info[3][5] =
{
                {
                    {"Joker", "03.00-4.50 PM", "04.04.2020", 350},
                    {"Shoplifters", "05.10-7.00 PM", "04.04.2020", 350},
                    {"Toy Story", "02.00-4.10 PM", "05.04.2020", 350},
                    {"Avengers: Endgame", "03.00-4.50 PM", "07.04.2020", 350},
                    {"Spider-Man: Far From Home", "02.00-4.10 PM", "08.04.2020", 350}
                },

                {
                    {"Kabir singh", "03.00-4.50 PM", "04.04.2020", 300},
                    {"Mission Mangal", "05.10-7.00 PM", "04.04.2020", 300},
                    {"Housefull 4", "02.00-4.10 PM", "05.04.2020", 300},
                    {"Dabangg 3", "03.00-4.50 PM", "07.04.2020", 300},
                    {"Dream Girl", "02.00-4.10 PM", "08.04.2020", 300}
                },

                {
                    {"Boxer", "03.00-4.50 PM", "04.04.2020", 250},
                    {"Total Dadagiri", "05.10-7.00 PM", "04.04.2020", 250},
                    {"Hoichoi Unlimited", "02.00-4.10 PM", "05.04.2020", 250},
                    {"Jonaki", "03.00-4.50 PM", "07.04.2020", 250},
                    {"Shonar Pahar", "02.00-4.10 PM", "08.04.2020", 250}
                }

};


void main()
{
    write_movie();

    main_screen();
}


void reg_info()
{
    printf("\n\n");

    int n, size;

    number = fopen("number.txt", "a+");

    fseek (number, 0, SEEK_END);
    size = ftell(number);

    if(size == 0)
        n = 0;

    else
    {
        rewind(number);
        n = getw(number);
    }

    printf("\n");

    printf("Enter Username: ");
    scanf("%s", data[n].username);
    fflush(stdin);

    printf("Enter password: ");
    scanf("%s", data[n].password);
    fflush(stdin);

    printf("Enter mobile number: ");
    scanf("%s", data[n].mobile);
    fflush(stdin);

    printf("Enter email: ");
    scanf("%s", data[n].email);
    fflush(stdin);

    printf("\n");

    customer = fopen("customer.txt","a+");

    if(customer != NULL)
    {
        fwrite(&data[n], sizeof(member), 1, customer);

        printf("Successfully added!\n");
        fclose(customer);
    }

    else
    {
        printf("Sorry! Not added!\n");
    }

    n++;

    number = fopen("number.txt", "w");
    putw(n, number);

    fclose(number);

}


void read_from_file()
{
    int index, n;
    char admin_id[50] = "Pappu", admin_pass[50] = "dipto";
    char input_id[50], input_pass[50];

    system("cls");

    printf("\n\t\t\t######## Admin Login #########\n\n");

    printf(" Enter admin id: ");
    scanf("%s", input_id);

    printf(" Enter admin password: ");
    scanf("%s", input_pass);

    if(((strcmp(admin_id, input_id) == 0)) && ((strcmp(admin_pass, input_pass)) == 0))
    {

        printf("\n\t\t  ######## Login Successful #########\n\n");
        printf("\n\t\t  ########     Welcome!!!     #######\n\n");
        printf("\n\n");

        customer = fopen("customer.txt","a+");
        number = fopen("number.txt", "a+");

        n = getw(number);
        fclose(number);

        printf("Enter any key to continue....");
        getch();
        system("cls");

        printf("\n\t\t  ######## Member List #########\n\n");

        for(index = 0; index < n; index++)
        {
            fread(&data[index], sizeof(member), 1, customer);

            printf(" Member Name: %s\n", data[index].username);
            printf(" Member Age: %s\n", data[index].password);
            printf(" Member Phone Number: %s\n", data[index].mobile);
            printf(" Member Email: %s\n\n\n", data[index].email);
        }
        fclose(customer);
    }

    else
    {
        printf("Invalid Input!\n");

        //main_screen();
    }
}



void write_movie()
{
    int i, j;
    char ch;

    file = fopen("movies.bin", "wb");

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
        {
            fwrite(&info[i][j], sizeof(movie), 1, file);
        }
    }

    fclose(file);

}


void main_screen()
{
    printf("\n\n\n");
    printf("          ==========================================================\n");
    printf("          ||                 BRONZE CITY CINEMAS                  ||\n");
    printf("          ||                ---------------------                 ||\n");
    printf("          ||                                                      ||\n");
    printf("          ||                 1. Buy Tickets                       ||\n");
    printf("          ||                                                      ||\n");
    printf("          ||                 2. Register(New members)             ||\n");
    printf("          ||                                                      ||\n");
    printf("          ||                 3. Customer list(Admin only)         ||\n");
    printf("          ||                                                      ||\n");
    printf("          ||                 4. Exit                              ||\n");
    printf("          ||                                                      ||\n");
    printf("          ==========================================================\n");

    printf("\n\n\n");

    int choice;

    printf(" Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {

    case 1:
       selection();
       break;

    case 2:
        reg_info();
        break;

    case 3:
        read_from_file();
        break;

    case 4:
        exit(0);
        break;


    }
}


void selection()
{
    int select;

    system("cls");

    printf("\n\n");
    printf(" _____________________^^Welcome to Bronze City Cinemas^^_____________________\n\n");
    printf("\t   ........What types of movie you want to see?.........\n");
    printf("\t                      1.Hollywood        \n");
    printf("\t                      2.Bollywood        \n");
    printf("\t                      3.Tollywood        \n");

    printf("\n       ** For selecting movie type you need to enter 1, 2 or 3 **\n");
    scanf("%d", &select);


    if(select == 1)
        hollywood();

    else if(select == 2)
        bollywood();

    else if(select == 3)
        tollywood();

}


void hollywood()
{
    int choice, genre = 0;

    system("cls");

    printf("\n                      Current Hollywood movie list :\n");
    printf("                     ................................\n");
    printf("\n Movie name                         Time            Date           Price\n");
    printf(" ............                      .......         .......        .........\n");
    printf("\n 1. Joker                        03.00-4.50 PM    04.04.2020       350 BDT\n");
    printf(" 2. Shoplifters                  05.10-7.00 PM    04.04.2020       350 BDT\n");
    printf(" 3. Toy Story 4                  02.00-4.10 PM    05.04.2020       350 BDT\n");
    printf(" 4. Avengers: Endgame            03.00-4.50 PM    07.04.2020       350 BDT\n");
    printf(" 5. Spider-Man: Far From Home    02.00-4.10 PM    08.04.2020       350 BDT\n");


    printf("\n Please Enter the serial no. of the movie you want to to watch: ");
    scanf("%d", &choice);

    choice -= 1;

    ticket(genre, choice);
}


void bollywood()
{
    int choice, genre = 1;

    system("cls");

    printf("\n                       Current Bollywood movie list :\n");
    printf("                      ................................\n");
    printf("\n Movie name                         Time           Date             Price\n");
    printf(" ............                      .......        .......         ........\n");
    printf("\n 1. Kabir singh                03.00-4.50 PM    04.04.2020        300 BDT\n");
    printf(" 2. Mission Mangal             05.10-7.00 PM    04.04.2020        300 BDT\n");
    printf(" 3. Housefull 4                02.00-4.10 PM    05.04.2020        300 BDT\n");
    printf(" 4. Dabangg 3                  03.00-4.50 PM    07.04.2020        300 BDT\n");
    printf(" 5. Dream Girl                 02.00-4.10 PM    08.04.2020        300 BDT\n");


    printf("\n Please Enter the movie code of the movie you want to to watch: ");
    scanf("%d", &choice);

    choice -= 1;

    ticket(genre, choice);
}


void tollywood()
{
    int choice, genre = 2;

    system("cls");

    fread(&info[genre][choice], sizeof(movie), 1, file);

    printf("\n                       Current Tollywood movie list :\n");
    printf("                      ................................\n");
    printf("\n Movie name                         Time             Date              Price\n");
    printf(" ............                      .......         .......            .........\n");
    printf("\n 1. Boxer                        03.00-4.50 PM    04.04.2020           250 BDT\n");
    printf(" 2. Total Dadagiri               05.10-7.00 PM    04.04.2020           250 BDT\n");
    printf(" 3. Hoichoi Unlimited            02.00-4.10 PM    05.04.2020           250 BDT\n");
    printf(" 4. Jonaki                       03.00-4.50 PM    07.04.2020           250 BDT\n");
    printf(" 5. Shonar Pahar                 02.00-4.10 PM    08.04.2020           250 BDT\n");


    printf("\n Please Enter the serial no. of the movie you want to to watch: ");
    scanf("%d", &choice);

    choice -= 1;

    ticket(genre, choice);
}


void ticket(int genre, int choice)
{
    system("cls");

    char temp_user[50], temp_pass[50];
    int n, i, price, num_ticket, total_price, flag = 0;

    printf("\n\t\t\t######## User Login #########\n\n");

    printf(" Enter username: ");
    scanf("%s", temp_user);

    printf("\n\n Enter password: ");
    scanf("%s", temp_pass);



    customer = fopen("customer.txt","a+");
    number = fopen("number.txt", "a+");

    n = getw(number);
    fclose(number);

    file = fopen("movies.bin", "rb");

    if(file == NULL)
    {
        printf("File not found");
    }

    else
    {
        fread(&info, sizeof(movie), 1, file);
    }

    for(i = 0; i < n; i++)
    {
        fread(&data[i], sizeof(member), 1, customer);

        if((strcmp(data[i].username, temp_user) == 0) && (strcmp(data[i].password, temp_pass) == 0))
        {
            flag = 1;

            system("cls");

            printf("\n\t\t\t######## Login Successful #########\n\n");
            printf("\n\t\t\t########     Welcome!!!     #######\n\n");

            printf("\n Please Enter the number of ticket(s) you want to purchase: ");
            scanf("%d", &num_ticket);

            price = info[genre][choice].price;
            total_price =  price * num_ticket;

            system("cls");

            printf("\n\n\t#########Your purchase info#########");

            printf("\n\n\n Movie Name: %s\n", info[genre][choice].m_name);
            printf("\n Movie Time: %s\n", info[genre][choice].time);
            printf("\n Movie Date: %s\n", info[genre][choice].date);
            printf("\n Customer Name: %s\n", data[i].username);
            printf("\n Customer Mobile: %s\n", data[i].mobile);
            printf("\n Customer Email: %s\n", data[i].email);
            printf("\n Ticket Quantity: %d\n", num_ticket);
            printf("\n Total price: %d\n", total_price);


            printf("\n\n\t***YAYY!!! You successfully purchased your tickets!***\n\n");
            printf("\t Your ticket(s) have been sent to your email address!\n\n");
            printf("\t\t\t\tThank You!\n\n");
            break;
        }
    }

    if(flag == 0)
    {
        printf("\n\t\t  ######## Login Unsuccessful #########\n\n");
        printf(" \t\t     Username / Password mismatch!!!\n\n");
    }
    getch();

}
