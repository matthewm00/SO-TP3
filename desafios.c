// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "desafios.h"

static t_game game;

static int check_answer(char *answer, char *entered);
static void print_challenge_header();
static void print_investigate_msg();
static int challenge_1();
static int challenge_2();
static int challenge_3();
static int challenge_4();
static int challenge_5();
static int challenge_6() __attribute__((section(".RUN_ME")));
static int challenge_7();
static int challenge_8();
static int challenge_9();
static int challenge_10();
static int challenge_11();
static int challenge_12();
static void gdbme();

static char too_easy = 1;

static char * welcome_msg[10] = {
"\x1B[35m  _______  _______            _________ _______  ______  \n",
"\x1B[35m (  ____ \\(  ___  )           \\__   __/(  ____ )/ ___  \\ \n",
"\x1B[35m | (    \\/| (   ) |              ) (   | (    )|\\/   \\  \\\n",
"\x1B[35m | (_____ | |   | |   _____      | |   | (____)|   ___) /\n",
"\x1B[35m (_____  )| |   | |  (_____)     | |   |  _____)  (___ ( \n",
"\x1B[35m       ) || |   | |              | |   | (            ) \\\n",
"\x1B[35m /\\____) || (___) |              | |   | )      /\\___/  /\n",
"\x1B[35m \\_______)(_______)              )_(   |/       \\______/ \n",
"\x1B[31mNicole Hinojo\x1B[0m - \x1B[32mSantiago Larroude\x1B[0m -\x1B[33m Mateo Menghini\x1B[0m\n",
"\x1B[0m\n\n"
};

static char * ans[CALLENGE_COUNT] = {
  "entendido\n",
  "itba\n",
  "M4GFKZ289aku\n",
  "fk3wfLCm3QvS\n",
  "too_easy\n",
  ".RUN_ME\n",
  "",
  "BUmyYq5XxXGt\n",
  "u^v\n",
  "chin_chu_lan_cha\n",
  "gdb_rules\n",
  "normal\n"
};

static const char challenge_header[] = "------------- DESAFIO -------------\n";
static const char investigate_msg[] = "----- PREGUNTA PARA INVESTIGAR -----\n";
static const char end_msg[] = "\nFelicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n";

void init(FILE *fp)
{
    printf(welcome_msg);

    game.fp = fp;
    game.level = 0;

    game.challenges[0] = &challenge_1;
    game.challenges[1] = &challenge_2;
    game.challenges[2] = &challenge_3;
    game.challenges[3] = &challenge_4;
    game.challenges[4] = &challenge_5;
    game.challenges[5] = &challenge_6;
    game.challenges[6] = &challenge_7;
    game.challenges[7] = &challenge_8;
    game.challenges[8] = &challenge_9;
    game.challenges[9] = &challenge_10;
    game.challenges[10] = &challenge_11;
    game.challenges[11] = &challenge_12;

    game.buffer = NULL;
    game.size = 0;
    srand(time(0));
}

int challenge(int challenge_id)
{
    system("clear");
    challenge_id--;
    game.level = challenge_id;
    print_challenge_header();
    return game.challenges[challenge_id]();
}

void end()
{
    system("clear");
    printf(end_msg);
    free(game.buffer);
}

static int challenge_1()
{
    printf(
        "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n"
        "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel."
        "Además tendrán que investigar otras preguntas para responder durante la defensa."
        "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos"
        " y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta."
        "Además, deberán implementar otro programa para comunicarse conmigo.\n\n"
        "Deberán estar atentos a los easter eggs.\n\n"
        "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n");
    print_investigate_msg();
    printf("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_1 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_2()
{
    printf(
        "The Wire S1E5\n"
        "5295 888 6288\n\n");
    print_investigate_msg();
    printf("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_2 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_3()
{
    printf("https://ibb.co/tc0Hb6w\n");
    print_investigate_msg();
    printf("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_3 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_4()
{
    char *res = "La respuesta es fk3wfLCm3QvS";
    if (write(13, res, strlen(res)) == -1)
    {
        perror("write");
    }
    printf("EBADF...\n\nwrite: Bad file descriptor\n");
    print_investigate_msg();
    printf(
        "¿Qué útil abstraccion es utilizada para comunicarse con sockets?"
        " ¿se puede utilizar read(2) y write(2) para operar?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_4 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_5()
{
    if (too_easy)
    {
        printf("respuesta = strings:250\n");
        print_investigate_msg();
        printf("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");

        if (getline(&game.buffer, &game.size, game.fp) == -1)
        {
            HANDLE_ERROR("challenge_5 function: error in getline");
        }
    }

    return check_answer(ans[game.level], game.buffer);
}

static int challenge_6()
{
    printf(".init .plt .text ? .fini .rodata .eh_frame_hdr\n");
    print_investigate_msg();
    printf(
        "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes."
        "¿Qué conviene más?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_6 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_7()
{
    printf("Filter error\n");

    char *answer_7 = "K5n2UFfpFMUN\n";
    int len = strlen(answer_7);
    for (int i = 0; i < len; i++)
    {
        printf("%c", answer_7[i]);
        for (int j = 0; j < (rand() % (20 - 6 + 1)) + 6; j++)
        {
            char a = (rand() % (122 - 65 + 1)) + 65;
            char aux[2] = {a, 0};
            write(2, aux, 1);
        }
    }
    printf("\n");
    print_investigate_msg();
    printf("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n");
    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_7 function: error in getline");
    }
    return check_answer(answer_7, game.buffer);
}

static int challenge_8()
{
    printf("¿?\n\n");
    printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n");
    print_investigate_msg();
    printf("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_8 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_9()
{
    printf(
        "Latexme\n"
        "Si\n"
        "\\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\n"
        "entonces\n"
        "y = \n");
    print_investigate_msg();
    printf("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_9 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_10()
{
    printf("quine\n\n");
    printf("\n");

    if (system("gcc quine.c -o quine") != 0)
    {
        printf("\nENTER para reinternar.\n");
    }
    else
    {
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");

        if (system("./quine | diff -quine.c") != 0)
        {
            printf("\n%s\n", "diff encontró diferencias.");
            printf("\nENTER para reinternar.\n");
        }
        else
        {
            printf("La respuesta es chin_chu_lan_cha\n\n");
        }
    }

    print_investigate_msg();
    printf("¿Cuáles son las características del protocolo SCTP?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_10 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_11()
{
    printf("b gdbme y encontrá el valor mágico\n");
    gdbme();
    print_investigate_msg();
    printf("¿Qué es un RFC?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_11 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static int challenge_12()
{
    printf("Me conoces\n");

    
    for (int i = 0; i < 1000; i++)
    {
        double x, y, aux;
        x = rand() / ((double)RAND_MAX + 1);
        y = rand() / ((double)RAND_MAX + 1);
        aux = sqrt(-2 * log(x)) * cos(2 * PIE * y);
        printf("%.6f ", aux);
    }
    putchar('\n');

    print_investigate_msg();
    printf("¿Fue divertido?\n");

    if (getline(&game.buffer, &game.size, game.fp) == -1)
    {
        HANDLE_ERROR("challenge_12 function: error in getline");
    }
    return check_answer(ans[game.level], game.buffer);
}

static void gdbme()
{
    if ((long)getpid() == 0x123456789)
    {
        printf("La respuesta es: gdb_rules\n\n");
    }
}

static void print_challenge_header()
{
    printf(challenge_header);
}

static void print_investigate_msg()
{
    printf(investigate_msg);
}

static int check_answer(char *answer, char *entered)
{
    int re = 1;
    if (strcmp(answer, entered) != 0)
    {
        printf("\nRespuesta incorrecta: %s\n", entered);
        sleep(1);
        re = 0;
    }
    return re;
}