/*
 * Expects, Ensures implemetation. Contract violations thow
 * pgsl::contract_violation by default
 *
 * To enable contract checking PGSL_ASSERT_ENABLE_CONTRACT_CHECKING
 *
 * If PGSL_ASSERT_LOG_ON_CONTRACT_VIOLATION is defined
 *
 *      Contract violations will be loged via PGSL_ASSERT_LOG_STREAM.
 *
 *      Requirements for PGSL_ASSERT_LOG_STREAM:
 *
 *          * Needs to have a opertor<<(const char*) defined
 *          * Needs to be globaly accesible
 *
 *      If PGSL_ASSERT_LOG_STREAM is not defined then std::cerr is used
 *
 * If PGSL_ASSERT_TERMINATE_ON_CONTRACT_VIOLATION is defined it will do the same
 * as in PGSL_ASSERT_LOG_ON_CONTRACT_VIOLATION but it will terminate the program
 *
 * Other reactions to contract violations are:
 *
 *      * PGSL_ASSERT_THROW_ON_CONTRACT_VIOLATION (The default if nothing is
 *        specified)
 *      * PGSL_ASSERT_RETURN_NULLOPT_ON_CONTRACT_VIOLATION
 *
 */

#ifndef PGSL_ASSERT_HPP
#define PGSL_ASSERT_HPP

#include <iostream>
#include <exception>

// The code base is for C++17 and forward, but I might use this file elsewhere,
// so this is here to check if it is posible
#if __cplusplus >= 201703L
    #include <optional>
#endif

#if defined(PGSL_ASSERT_ENABLE_CONTRACT_CHECKING)

    /*
     *
     *  Utilities
     *
     */

    #define PGSL_TO_STRING(x)  PGSL_TO_STRING2(x)
    #define PGSL_TO_STRING2(x) #x

    #define PGSL_ASSERT_FILE_LOCATION \
        "<File: '" __FILE__ "', Line: " PGSL_TO_STRING(__LINE__) ">"

    #if !defined(PGSL_ASSERT_LOG_ON_CONTRACT_VIOLATION) \
        && !defined(PGSL_ASSERT_THROW_ON_CONTRACT_VIOLATION) \
        && !defined(PGSL_ASSERT_TERMINATE_ON_CONTRACT_VIOLATION) \
        && !defined(PGSL_ASSERT_RETURN_NULLOPT_ON_CONTRACT_VIOLATION)

        #define PGSL_ASSERT_THROW_ON_CONTRACT_VIOLATION
    #endif

    #define PGSL_CONTRACT_VIOLATION_STRING(contract_type, condition) \
        contract_type " violation: " PGSL_TO_STRING( \
            condition) " on " PGSL_ASSERT_FILE_LOCATION

    #if !defined(PGSL_ASSERT_LOG_STREAM)
        #define PGSL_ASSERT_LOG_STREAM ::std::cerr
    #endif

    /*
     *
     * Handling depending on the user specification
     *
     */

    #if defined(PGSL_ASSERT_LOG_ON_CONTRACT_VIOLATION)

        #define PGSL_ACT_ON_CONTRACT_VIOLATION(contract_type, condition) \
            if (!(condition)) { \
                PGSL_ASSERT_LOG_STREAM \
                    << PGSL_CONTRACT_VIOLATION_STRING(contract_type, \
                                                      condition) \
                    << "\n"; \
            }

    #elif defined(PGSL_ASSERT_THROW_ON_CONTRACT_VIOLATION)

        #define PGSL_ACT_ON_CONTRACT_VIOLATION(contract_type, condition) \
            if (!(condition)) { \
                throw pgsl::contract_violation( \
                    PGSL_CONTRACT_VIOLATION_STRING(contract_type, condition)); \
            }

    #elif defined(PGSL_ASSERT_TERMINATE_ON_CONTRACT_VIOLATION)

        #define PGSL_ACT_ON_CONTRACT_VIOLATION(contract_type, condition) \
            if (!(condition)) { \
                PGSL_ASSERT_LOG_STREAM \
                    << PGSL_CONTRACT_VIOLATION_STRING(contract_type, \
                                                      condition) \
                    << "\n"; \
                ::std::terminate(); \
            }

    #elif defined(PGSL_ASSERT_RETURN_NULLOPT_ON_CONTRACT_VIOLATION)

        #define PGSL_ACT_ON_CONTRACT_VIOLATION(contract_type, condition) \
            if (!(condition)) { \
                return ::std::nullopt; \
            }

    #endif

    #define Expects(condition) \
        PGSL_ACT_ON_CONTRACT_VIOLATION("Precondition", condition)
    #define Ensures(condition) \
        PGSL_ACT_ON_CONTRACT_VIOLATION("Postcondition", condition)

    #define Axiom(condition) (void)0 // NOLINT Needs to be a macro
#else

    #define Expects(condition) (void)0 // NOLINT Needs to be a macro
    #define Ensures(condition) (void)0 // NOLINT Needs to be a macro
    #define Axiom(condition)   (void)0 // NOLINT Needs to be a macro

#endif

namespace pgsl {

class contract_violation : public std::exception {
   public:
    inline explicit contract_violation(const char *message)
        : message(message) {}

    [[nodiscard]] inline const char *what() const noexcept override {
        return message;
    }

   private:
    const char *message = "pgsl::contract_violation";
};

} // namespace pgsl

#endif
