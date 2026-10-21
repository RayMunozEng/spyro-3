#ifndef SPYRO_MATCHING_ANNOTATIONS_H
#define SPYRO_MATCHING_ANNOTATIONS_H

/* AI generated; not yet human reviewed.
 *
 * Examples (compiler annotations only):
 *     MATCHING_KEEP(currentValue);
 *     MATCHING_KEEP2(firstValue, secondValue);
 *     MATCHING_OBSERVE_VOLATILE(currentValue);
 *     MATCHING_BARRIER_VOLATILE("memory");
 *
 * Matching compiler annotations: every assembly template is empty.
 * KEEP preserves the original tied input/output constraints; OBSERVE reads
 * the original register operands; BARRIER states only its explicit compiler
 * clobber. No template emits an explicit CPU instruction, initializes an operand, proves
 * a value producer, or adds a C scope. Volatile spellings stay distinct.
 * Constraints may affect compiler-generated loads, copies, spills and scheduling.
 * Definitions deliberately add no parentheses, do/while, or semicolon.
 * Use only where exact original expansion and all native gates are checked.
 */

#define MATCHING_BARRIER(clobber) __asm__("" : : : clobber)
#define MATCHING_BARRIER_GNU_VOLATILE(clobber) __asm__ __volatile__("" : : : clobber)
#define MATCHING_BARRIER_VOLATILE(clobber) __asm__ volatile("" : : : clobber)
#define MATCHING_KEEP(value0) __asm__("" : "=r"(value0) : "0"(value0))
#define MATCHING_KEEP2(value0, value1) \
    __asm__("" : "=r"(value0), "=r"(value1) : "0"(value0), "1"(value1))
#define MATCHING_KEEP2_CLOBBER(value0, value1, clobber) \
    __asm__("" : "=r"(value0), "=r"(value1) : "0"(value0), "1"(value1) : clobber)
#define MATCHING_KEEP2_GNU_VOLATILE(value0, value1) \
    __asm__ __volatile__("" : "=r"(value0), "=r"(value1) : "0"(value0), "1"(value1))
#define MATCHING_KEEP2_GNU_VOLATILE_CLOBBER(value0, value1, clobber) \
    __asm__ __volatile__("" : "=r"(value0), "=r"(value1) : "0"(value0), "1"(value1) : clobber)
#define MATCHING_KEEP2_VOLATILE(value0, value1) \
    __asm__ volatile("" : "=r"(value0), "=r"(value1) : "0"(value0), "1"(value1))
#define MATCHING_KEEP2_VOLATILE_CLOBBER(value0, value1, clobber) \
    __asm__ volatile("" : "=r"(value0), "=r"(value1) : "0"(value0), "1"(value1) : clobber)
#define MATCHING_KEEP3(value0, value1, value2) \
    __asm__("" : "=r"(value0), "=r"(value1), "=r"(value2) : "0"(value0), "1"(value1), "2"(value2))
#define MATCHING_KEEP3_CLOBBER(value0, value1, value2, clobber) \
    __asm__(""                                                  \
            : "=r"(value0), "=r"(value1), "=r"(value2)          \
            : "0"(value0), "1"(value1), "2"(value2)             \
            : clobber)
#define MATCHING_KEEP3_VOLATILE(value0, value1, value2)         \
    __asm__ volatile(""                                         \
                     : "=r"(value0), "=r"(value1), "=r"(value2) \
                     : "0"(value0), "1"(value1), "2"(value2))
#define MATCHING_KEEP3_VOLATILE_CLOBBER(value0, value1, value2, clobber) \
    __asm__ volatile(""                                                  \
                     : "=r"(value0), "=r"(value1), "=r"(value2)          \
                     : "0"(value0), "1"(value1), "2"(value2)             \
                     : clobber)
#define MATCHING_KEEP4(value0, value1, value2, value3)               \
    __asm__(""                                                       \
            : "=r"(value0), "=r"(value1), "=r"(value2), "=r"(value3) \
            : "0"(value0), "1"(value1), "2"(value2), "3"(value3))
#define MATCHING_KEEP4_CLOBBER(value0, value1, value2, value3, clobber) \
    __asm__(""                                                          \
            : "=r"(value0), "=r"(value1), "=r"(value2), "=r"(value3)    \
            : "0"(value0), "1"(value1), "2"(value2), "3"(value3)        \
            : clobber)
#define MATCHING_KEEP4_VOLATILE(value0, value1, value2, value3)               \
    __asm__ volatile(""                                                       \
                     : "=r"(value0), "=r"(value1), "=r"(value2), "=r"(value3) \
                     : "0"(value0), "1"(value1), "2"(value2), "3"(value3))
#define MATCHING_KEEP4_VOLATILE_CLOBBER(value0, value1, value2, value3, clobber) \
    __asm__ volatile(""                                                          \
                     : "=r"(value0), "=r"(value1), "=r"(value2), "=r"(value3)    \
                     : "0"(value0), "1"(value1), "2"(value2), "3"(value3)        \
                     : clobber)
#define MATCHING_KEEP5(value0, value1, value2, value3, value4)                     \
    __asm__(""                                                                     \
            : "=r"(value0), "=r"(value1), "=r"(value2), "=r"(value3), "=r"(value4) \
            : "0"(value0), "1"(value1), "2"(value2), "3"(value3), "4"(value4))
#define MATCHING_KEEP5_CLOBBER(value0, value1, value2, value3, value4, clobber)    \
    __asm__(""                                                                     \
            : "=r"(value0), "=r"(value1), "=r"(value2), "=r"(value3), "=r"(value4) \
            : "0"(value0), "1"(value1), "2"(value2), "3"(value3), "4"(value4)      \
            : clobber)
#define MATCHING_KEEP5_VOLATILE_CLOBBER(value0, value1, value2, value3, value4, clobber)    \
    __asm__ volatile(""                                                                     \
                     : "=r"(value0), "=r"(value1), "=r"(value2), "=r"(value3), "=r"(value4) \
                     : "0"(value0), "1"(value1), "2"(value2), "3"(value3), "4"(value4)      \
                     : clobber)
#define MATCHING_KEEP_CLOBBER(value0, clobber) __asm__("" : "=r"(value0) : "0"(value0) : clobber)
#define MATCHING_KEEP_GNU_VOLATILE(value0) __asm__ __volatile__("" : "=r"(value0) : "0"(value0))
#define MATCHING_KEEP_GNU_VOLATILE_CLOBBER(value0, clobber) \
    __asm__ __volatile__("" : "=r"(value0) : "0"(value0) : clobber)
#define MATCHING_KEEP_VOLATILE(value0) __asm__ volatile("" : "=r"(value0) : "0"(value0))
#define MATCHING_KEEP_VOLATILE_CLOBBER(value0, clobber) \
    __asm__ volatile("" : "=r"(value0) : "0"(value0) : clobber)
#define MATCHING_OBSERVE(value0) __asm__("" : : "r"(value0))
#define MATCHING_OBSERVE2(value0, value1) __asm__("" : : "r"(value0), "r"(value1))
#define MATCHING_OBSERVE2_CLOBBER(value0, value1, clobber) \
    __asm__("" : : "r"(value0), "r"(value1) : clobber)
#define MATCHING_OBSERVE2_GNU_VOLATILE(value0, value1) \
    __asm__ __volatile__("" : : "r"(value0), "r"(value1))
#define MATCHING_OBSERVE2_GNU_VOLATILE_CLOBBER(value0, value1, clobber) \
    __asm__ __volatile__("" : : "r"(value0), "r"(value1) : clobber)
#define MATCHING_OBSERVE2_VOLATILE(value0, value1) __asm__ volatile("" : : "r"(value0), "r"(value1))
#define MATCHING_OBSERVE2_VOLATILE_CLOBBER(value0, value1, clobber) \
    __asm__ volatile("" : : "r"(value0), "r"(value1) : clobber)
#define MATCHING_OBSERVE3(value0, value1, value2) \
    __asm__("" : : "r"(value0), "r"(value1), "r"(value2))
#define MATCHING_OBSERVE3_CLOBBER(value0, value1, value2, clobber) \
    __asm__("" : : "r"(value0), "r"(value1), "r"(value2) : clobber)
#define MATCHING_OBSERVE3_GNU_VOLATILE_CLOBBER(value0, value1, value2, clobber) \
    __asm__ __volatile__("" : : "r"(value0), "r"(value1), "r"(value2) : clobber)
#define MATCHING_OBSERVE3_VOLATILE(value0, value1, value2) \
    __asm__ volatile("" : : "r"(value0), "r"(value1), "r"(value2))
#define MATCHING_OBSERVE3_VOLATILE_CLOBBER(value0, value1, value2, clobber) \
    __asm__ volatile("" : : "r"(value0), "r"(value1), "r"(value2) : clobber)
#define MATCHING_OBSERVE4(value0, value1, value2, value3) \
    __asm__("" : : "r"(value0), "r"(value1), "r"(value2), "r"(value3))
#define MATCHING_OBSERVE4_CLOBBER(value0, value1, value2, value3, clobber) \
    __asm__("" : : "r"(value0), "r"(value1), "r"(value2), "r"(value3) : clobber)
#define MATCHING_OBSERVE4_VOLATILE(value0, value1, value2, value3) \
    __asm__ volatile("" : : "r"(value0), "r"(value1), "r"(value2), "r"(value3))
#define MATCHING_OBSERVE4_VOLATILE_CLOBBER(value0, value1, value2, value3, clobber) \
    __asm__ volatile("" : : "r"(value0), "r"(value1), "r"(value2), "r"(value3) : clobber)
#define MATCHING_OBSERVE5(value0, value1, value2, value3, value4) \
    __asm__("" : : "r"(value0), "r"(value1), "r"(value2), "r"(value3), "r"(value4))
#define MATCHING_OBSERVE5_VOLATILE(value0, value1, value2, value3, value4) \
    __asm__ volatile("" : : "r"(value0), "r"(value1), "r"(value2), "r"(value3), "r"(value4))
#define MATCHING_OBSERVE_CLOBBER(value0, clobber) __asm__("" : : "r"(value0) : clobber)
#define MATCHING_OBSERVE_GNU_VOLATILE(value0) __asm__ __volatile__("" : : "r"(value0))
#define MATCHING_OBSERVE_GNU_VOLATILE_CLOBBER(value0, clobber) \
    __asm__ __volatile__("" : : "r"(value0) : clobber)
#define MATCHING_OBSERVE_VOLATILE(value0) __asm__ volatile("" : : "r"(value0))
#define MATCHING_OBSERVE_VOLATILE_CLOBBER(value0, clobber) \
    __asm__ volatile("" : : "r"(value0) : clobber)

#endif
