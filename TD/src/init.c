extern char _bss_start, _bss_end, _text_start, _text_end, _data_start, _data_end, _vtable_start, _vtable_end, _dataload, _textload, _vtableload;


void __attribute__ ((section(".bootloader"))) init_memory()
{
    char* i;
    for(i = &_bss_start; i < &_bss_end; i++)
    {
        *i = 0;   
    }

    char* j = &_dataload;
    for(i = &_data_start; i < &_data_end; i++, j++)
    {
        *i = *j;   
    }
    
    j = &_textload;
    for(i = &_text_start; i < &_text_end; i++, j++)
    {
        *i = *j;   
    }
    
    j = &_vtableload;
    for(i = &_vtable_start; i < &_vtable_end; i++, j++)
    {
        *i = *j;   
    }
}
