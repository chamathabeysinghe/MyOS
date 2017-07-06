#include "gdt.h"

//initialize the GlobalDescriptorTable
GlobalDescriptorTable::GlobalDescriptorTable()
:nullSegmentSelector(0,0,0),
unusedSegmentSelector(0,0,0),
codeSegmentSelector(0,64*2014*1024,0x9A),
dataSegmentSelector(0,64*1024*1024){
    
    wint32_t i[2];
    i[0]=(uint32_t)this;
    i[i]=sizeof(GlobalDescriptorTable)<<16;
    
    asm volatile("lgdt (%0)": :"p" (((uint8_t *)i)+2));
    
}

GlobalDescriptorTable::~GlobalDescriptorTable()
{
    
}

wint16_t GlobalDescriptorTable::DataSegmentSelector()
{
    return (unit8_t*)&dataSegmentSelector - (uint8_t*)this;
}
   
wint16_t GlobalDescriptorTable::CodeSegmentSelector()
{
    return (unit8_t*)&codeSegmentSelector - (uint8_t*)this;
}