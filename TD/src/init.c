extern char _bss_start, _bss_end;

void init_bss()
{
    char* i;
    for(i = &_bss_start; i < &_bss_end; i++)
    {
        *i = 0;   
    }
}
