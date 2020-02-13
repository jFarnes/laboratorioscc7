#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

/* sorting structs using qsort() example */ 
void sort_structs_example(void) 
{ 
    struct st_ex structs[] = {{"mp3 player", 299.0f}, {"plasma tv", 2200.0f}, 
                              {"notebook", 1300.0f}, {"smartphone", 499.99f}, 
                              {"dvd player", 150.0f}, {"matches", 0.2f }};
 
    size_t structs_len = sizeof(structs) / sizeof(struct st_ex);
 
    puts("*** Struct sorting (price)...");
 
    /* print original struct array */ 
    print_struct_array(structs, structs_len);
 
    /* sort array using qsort functions */ 
    qsort(structs, structs_len, sizeof(struct st_ex), struct_cmp_by_price);
 
    /* print sorted struct array */ 
    print_struct_array(structs, structs_len);
 
    puts("*** Struct sorting (product)...");
 
    /* resort using other comparision function */ 
    qsort(structs, structs_len, sizeof(struct st_ex), struct_cmp_by_product);    
 
    /* print sorted struct array */ 
    print_struct_array(structs, structs_len);
} 
 
 