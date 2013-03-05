void func()
{
    int *foo = 0;
    *foo = 0;
}

int main()
{
    func();
    return 0;
}
