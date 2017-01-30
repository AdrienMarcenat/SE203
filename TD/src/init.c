extern char _bss_start, _bss_end, _text_start, _text_end, _data_start, _data_end, _vtable_start, _vtable_end, _dataload, _textload, _vtableload;

void init_memory()
{
    char* i;
    for(i = &_bss_start; i < &_bss_end; i++)
    {
        *i = 0;   
    }

    for(i = &_data_start; i < &_data_end; i++)
    {
        *i = _dataload;   
    }
    
    for(i = &_text_start; i < &_text_end; i++)
    {
        *i = _textload;   
    }
    
    for(i = &_vtable_start; i < &_vtable_end; i++)
    {
        *i = _vtableload;   
    }
}
