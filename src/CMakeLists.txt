set(XCALC_LIB ${PROJECT_NAME})

if(APPLE)
    set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
endif(APPLE)

set(PUBLIC_SOURCES ./public/xcalc.cpp ./public/include/xcalc.h public/include/DegreeMode.h)
set(INTERNAL_SOURCES ./internal/Tokenizer.cpp ./internal/Tokenizer.h
                     internal/Parser.cpp internal/Parser.h
                     internal/terms/Terms.h
                     internal/expressions/Expression.h
                     internal/expressions/ArithmeticExpression.cpp internal/expressions/ArithmeticExpression.h
                     internal/expressions/DecimalExpression.cpp internal/expressions/DecimalExpression.h
                     internal/expressions/VariableExpression.cpp internal/expressions/VariableExpression.h
                     internal/expressions/FunctionExpression.cpp internal/expressions/FunctionExpression.h
                     internal/expressions/UnaryExpression.cpp internal/expressions/UnaryExpression.h
                     internal/constants/ConstantsProvider.cpp internal/constants/ConstantsProvider.h
                     internal/operators/OperatorsProvider.cpp internal/operators/OperatorsProvider.h
                     internal/functions/FunctionsProvider.cpp internal/functions/FunctionsProvider.h
                     internal/utils/Formatter.h
                     internal/utils/AngleUnitsProvider.cpp internal/utils/AngleUnitsProvider.h internal/utils/EvaluationError.h internal/utils/EvaluationError.cpp)

add_library(${XCALC_LIB} SHARED ${PUBLIC_SOURCES} ${INTERNAL_SOURCES})
target_include_directories(${XCALC_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public/include)
