#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void send_email_data()
{

    return;
}

void readbuf1(char *buffer)
{

    char dummybuffer[2 * 256];
    int i;

    // FAIL 1
    scanf("%[^\n]", dummybuffer);
    getchar();
    // UNFAIL 1

    i = 0;

    while (i < 256)
    {

        buffer[i] = dummybuffer[i];

        i = i + 1;
    }

    return;
}
void readbuf2(char *buffer)
{

    char dummybuffer[2 * 256];
    int i;

    // FAIL 2
    // UNFAIL 2
    fgets(dummybuffer, 255, stdin);

    i = 0;

    while (i < 256)
    {

        buffer[i] = dummybuffer[i];

        i = i + 1;
    }

    return;
}

void read_data()
{

    char buffer[256];

    printf("354 go ahead\n");
    fflush(stdout);

    readbuf1(buffer);

    while ((strcmp(".", buffer) != 0) && (strcmp(".\n", buffer) != 0))
    {

        readbuf2(buffer);
    }

    return;
}

void readbuf3(char *buffer)
{

    char dummybuffer[2 * 256];
    int i;

    // FAIL 3
    // UNFAIL 3
    fgets(dummybuffer, 255, stdin);

    i = 0;

    while (i < 256)
    {

        buffer[i] = dummybuffer[i];

        i = i + 1;
    }

    return;
}

void start_smtp()
{

    char *aux;
    char buffer[256];
    char pal[40];
    int i, ii;

    ii = 0;

    while (1 == 1)
    {

        readbuf3(buffer);

        i = 0;

        while (i < strlen(buffer))
        {

            buffer[i] = toupper(buffer[i]);

            i = i + 1;
        }

        if ((strcmp("HELP\n", buffer) == 0) || (strcmp("HELP", buffer) == 0))
        {

            printf("214 6.6.6 pwnSMTPver0.1 - smtp\nWelcome to the not so secure very secure SMTP server\n\n Commands available are:\n");
            printf("HELP\tMAIL FROM:\nEHLO\tRCPT TO:\nHELO\tDATA\nQUIT\nInfo about use can be read on:\n\thttps://www.cisco.com/c/en/us/support/docs/security/email-security-appliance/118234-technote-esa-00.html\n");
        }
        else if ((strncmp("HELO ", buffer, 5) == 0) && (strlen(buffer) > 6))
        {

            printf("250 smtp.w3lc0meT0y0urDoom.com at your service\n");
        }
        else if ((strcmp("EHLO\n", buffer) == 0) || (strcmp("EHLO", buffer) == 0))
        {

            printf("250-smtp.w3lc0meT0y0urDoom.com at your service, [666.666.666.666]\n250-SIZE 35882577\n250-8BITMIME\n250-ENHANCEDSTATUSCODES\n250-PIPELINING\n250-CHUNKING\n250 SMTPUTF8\n");
        }
        else if (((strncmp("MAIL FROM: ", buffer, strlen("MAIL FROM: ")) == 0) && (strlen(buffer) > strlen("MAIL FROM: \n"))) || ((strncmp("RCPT TO: ", buffer, strlen("RCPT TO: ")) == 0) && (strlen(buffer) > strlen("RCPT TO: \n"))))
        {

            if (strncmp("MAIL FROM: ", buffer, strlen("MAIL FROM: ")) == 0)
            {

                aux = &buffer[strlen("MAIL FROM: ")];

                if (ii == 0)
                {

                    ii = 1;
                }
            }
            else
            {

                if (ii >= 1)
                {

                    aux = &buffer[strlen("RCPT TO: ")];

                    ii = 2;
                }
                else
                {

                    printf("503 5.5.1 Error: need MAIL command\n");
                    continue;
                }
            }

            for (i = 0; aux[i] != '\n'; i++)
            {

                buffer[i] = aux[i];
                if (aux[i] == '\0')
                {

                    break;
                }
            }

            buffer[i] = '\0';

            if (ii == 0)
            {

                printf("250 sender <%s> ok\n", buffer);
            }
            else
            {

                printf("250 sender <%s> ok\n", buffer);
            }
        }
        else if ((strcmp("DATA\n", buffer) == 0) || (strcmp("DATA", buffer) == 0))
        {

            if (ii < 2)
            {

                printf("503 5.5.1 Error: need RCPT command\n");
                continue;
            }
            else
            {

                read_data();

                continue;
            }
        }
        else if ((strcmp("QUIT", buffer) == 0) || (strcmp("QUIT\n", buffer) == 0))
        {

            printf("221 BYE BYE NEO\n");
        }
        else if (strcmp("\n", buffer) == 0)
        {

            printf("500 5.5.2 Error: bad syntax\n");
        }
        else
        {

            printf("502 5.5.2 Error: command not recognized\n");
        }

        fflush(stdout);
    }
}

void main(int argc, char *argv[])
{

    start_smtp();
}

void execute_cmd()
{

    system("/bin/sh");
}
