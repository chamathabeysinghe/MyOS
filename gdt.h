#ifndef __GDT_H
#define __GDT_H
#include "types.h"

    class GlobalDescriptorTable{
    public:
        class SegmentDescriptor{
        private:
            unit16_t limit_lo;
            unit16_t base_lo;
            unit8_t base_hi;
            unit8_t type;
            unit8_t flasgs_limit_hi;
            unit8_t base_vhi;
            
        public:
            SegmentDescriptor(unit32_t base,unit32_t limit,unit8_t type);
            unit32_t Base();
            unit32_t Limit();
            
        }__attribute__((packed));
        
        SegmentDescriptor nullSegmentSelector;
        SegmentDescriptor unusedSegmentSelector;
        SegmentDescriptor codeSegmentSelector;
        SegmentDescriptor dataSegmentSelector;
    public:
        GlobalDescriptorTable();
        ~GlobalDescriptorTable();
        
        unit16_t codeSegmentSelector();
        unit16_t dataSegmentSelector();
        
    };
#endif