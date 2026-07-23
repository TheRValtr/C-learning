int countdown(int number)
{
    int count = 0;

    while (number > 0)
    {
        number--;
        count++;
    }

    return count;
}