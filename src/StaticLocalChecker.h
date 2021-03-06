//== StaticLocalChecker.h - Checks for non-const static locals --------------*- C++ -*--==//
//
// by Thomas Hauth [ Thomas.Hauth@cern.ch ]
//
//===----------------------------------------------------------------------===//

// Checks for non-const method local statics which might not be thread-safe

#ifndef Utilities_StaticAnalyzers_StaticLocalChecker_h
#define Utilities_StaticAnalyzers_StaticLocalChecker_h

#include <clang/StaticAnalyzer/Core/Checker.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h>
#include <clang/StaticAnalyzer/Core/BugReporter/BugType.h>

#include "SasException.h"

namespace sas
{
   class StaticLocalChecker : public clang::ento::Checker<clang::ento::check::ASTDecl<clang::VarDecl>>
   {
      mutable std::unique_ptr<clang::ento::BuiltinBug> BT;

    public:
      void checkASTDecl(const clang::VarDecl* D, clang::ento::AnalysisManager& Mgr, clang::ento::BugReporter& BR) const;

    private:
      SasException m_exception;
   };
}

#endif
