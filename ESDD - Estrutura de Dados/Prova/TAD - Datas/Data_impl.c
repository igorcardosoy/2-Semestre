#include "Data.h"

struct type_data
{
    int dia;
    int mes;
    int ano;
};

bool criarData(int dia, int mes, int ano, Data* data)
{
    Data dataTemp;
    dataTemp = malloc(sizeof(struct type_data));

    dataTemp->ano = ano;
    dataTemp->dia = dia;
    dataTemp->mes = mes;

    if (ehValida(dataTemp))
    {
        free(dataTemp);
        (*data) = malloc(sizeof(struct type_data));
        (*data)->ano = ano;
        (*data)->mes = mes;
        (*data)->dia = dia;

        return true;
    }
    else
    {
        free(dataTemp);
        return false;
    }
}

bool ehValida(Data data)
{
    if (data->ano > 0 && data->dia > 0 && data->mes > 0)
    {
        switch (data->mes)
        {
        case 2:
            if (data->dia <= 28)
            {
                return true;
            }
            else if (data->dia == 29)
            {
                if (data->ano % 4 == 0)
                {
                    if ((data->ano % 100) != 0 || (data->ano % 400) == 0)
                    {
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        default:
            if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11)
            {
                return data->dia <= 30 ? true : false;
            }
            else if (data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12)
            {
                return data->dia <= 31 ? true : false;
            }
        }
    }
    return false;
}

bool criarDataDeString(char *dataString, Data* data)
{
    int dia = 0, mes = 0, ano = 0;
    int i = 0;

    while (dataString[i] != '\0')
    {
        switch (i)
        {
        case 0:
            switch (dataString[i])
            {
            case '0':
                dia = 0;
                break;
            case '1':
                dia = 10;
                break;
            case '2':
                dia = 20;
                break;
            case '3':
                dia = 30;
                break;
            default:
                break;
            }
            break;
        case 1:
            switch (dataString[i])
            {
            case '0':
                break;
            case '1':
                dia += 1;
                break;
            case '2':
                dia += 2;
                break;
            case '3':
                dia += 3;
                break;
            case '4':
                dia += 4;
                break;
            case '5':
                dia += 5;
                break;
            case '6':
                dia += 6;
                break;
            case '7':
                dia += 7;
                break;
            case '8':
                dia += 8;
                break;
            case '9':
                dia += 9;
                break;
            default:
                break;
            }
            break;
        case 2:
            break;
        case 3:
            switch (dataString[i])
            {
            case '0':
                mes = 0;
                break;
            case '1':
                mes = 10;
                break;
            default:
                break;
            }
            break;
        case 4:
            switch (dataString[i])
            {
            case '0':
                break;
            case '1':
                mes += 1;
                break;
            case '2':
                mes += 2;
                break;
            case '3':
                mes += 3;
                break;
            case '4':
                mes += 4;
                break;
            case '5':
                mes += 5;
                break;
            case '6':
                mes += 6;
                break;
            case '7':
                mes += 7;
                break;
            case '8':
                mes += 8;
                break;
            case '9':
                mes += 9;
                break;
            default:
                break;
            }
            break;
        case 5:
            break;
        case 6:  
            switch (dataString[i])
            {
            case '0':
                ano = 0;
                break;
            case '1':
                ano = 1000;
                break;
            case '2':
                ano = 2000;
                break;
            case '3':
                ano = 3000;
                break;
            case '4':
                ano = 4000;
                break;
            case '5':
                ano = 5000;
                break;
            case '6':
                ano = 6000;
                break;
            case '7':
                ano = 7000;
                break;
            case '8':
                ano = 8000;
                break;
            case '9':
                ano = 9000;
                break;
            default:
                break;
            }
            break;
        case 7:
            switch (dataString[i])
            {
                case '0':
                    break;
                case '1':
                    ano += 100;
                    break;
                case '2':
                    ano += 200;
                    break;
                case '3':
                    ano += 300;
                    break;
                case '4':
                    ano += 400;
                    break;
                case '5':
                    ano += 500;
                    break;
                case '6':
                    ano += 600;
                    break;
                case '7':
                    ano += 700;
                    break;
                case '8':
                    ano += 800;
                    break;
                case '9':
                    ano += 900;
                    break;
                default:
                    break;
            }
            break;
        case 8:
            switch (dataString[i])
            {
                case '0':
                    break;
                case '1':
                    ano += 10;
                    break;
                case '2':
                    ano += 20;
                    break;
                case '3':
                    ano += 30;
                    break;
                case '4':
                    ano += 40;
                    break;
                case '5':
                    ano += 50;
                    break;
                case '6':
                    ano += 60;
                    break;
                case '7':
                    ano += 70;
                    break;
                case '8':
                    ano += 80;
                    break;
                case '9':
                    ano += 90;
                    break;
                default:
                    break;
            }
            break;
        case 9:
            switch (dataString[i])
            {
            case '0':
                break;
            case '1':
                ano += 1;
                break;
            case '2':
                ano += 2;
                break;
            case '3':
                ano += 3;
                break;
            case '4':
                ano += 4;
                break;
            case '5':
                ano += 5;
                break;
            case '6':
                ano += 6;
                break;
            case '7':
                ano += 7;
                break;
            case '8':
                ano += 8;
                break;
            case '9':
                ano += 9;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        i++;
    }
    
    return criarData(dia, mes, ano, &(*data)) ? true : false;
}

int compararData(Data data1, Data data2)
{

    if (ehValida(data1) && ehValida(data2))
    {
        if (data1->ano == data2->ano)
        {
            if (data1->mes == data2->mes)
            {
                if (data1->dia == data2->dia)
                {
                    return 0;
                }
                else if (data1->dia > data2->dia)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
                
            }
            else if (data1->mes > data2->mes)
            {
                return 1;
            }
            else
            {
                return -1;
            }
            
        }
        else if (data1->ano > data2->ano)
        {
            return 1;
        }
        else
        {
            return -1;
        }
        
    }

    return -1;
}

char *toString(Data data)
{

    if (ehValida(data))
    {
        char *string;
        string = malloc(sizeof(int) * 35);

        switch (data->mes)
        {
        case 1:
            snprintf(string, 35, "%d de janeiro de %d", data->dia, data->ano);
            break;
        case 2:
            snprintf(string, 35, "%d de fevereiro de %d", data->dia, data->ano);
            break;
        case 3:
            snprintf(string, 35, "%d de marco de %d", data->dia, data->ano);
            break;
        case 4:
            snprintf(string, 35, "%d de abril de %d", data->dia, data->ano);
            break;
        case 5:
            snprintf(string, 35, "%d de maio de %d", data->dia, data->ano);
            break;
        case 6:
            snprintf(string, 35, "%d de junho de %d", data->dia, data->ano);
            break;
        case 7:
            snprintf(string, 35, "%d de julho de %d", data->dia, data->ano);
            break;
        case 8:
            snprintf(string, 35, "%d de agosto de %d", data->dia, data->ano);
            break;
        case 9:
            snprintf(string, 35, "%d de setembro de %d", data->dia, data->ano);
            break;
        case 10:
            snprintf(string, 35, "%d de outubro de %d", data->dia, data->ano);
            break;
        case 11:
            snprintf(string, 35, "%d de novembro de %d", data->dia, data->ano);
            break;
        case 12:
            snprintf(string, 35, "%.2d de dezembro de %d", data->dia, data->ano);
            break;
        default:
            break;
        }
        return string;
    }

    return "Data invalida";
};
