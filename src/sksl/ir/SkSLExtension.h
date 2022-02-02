/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SKSL_EXTENSION
#define SKSL_EXTENSION

#include "include/private/SkSLProgramElement.h"

namespace SkSL {

/**
 * An extension declaration.
 */
class Extension final : public ProgramElement {
public:
    inline static constexpr Kind kProgramElementKind = Kind::kExtension;

    Extension(int line, std::string_view name)
        : INHERITED(line, kProgramElementKind)
        , fName(name) {}

    std::string_view name() const {
        return fName;
    }

    std::unique_ptr<ProgramElement> clone() const override {
        return std::unique_ptr<ProgramElement>(new Extension(fLine, this->name()));
    }

    String description() const override {
        return "#extension " + SkSL::String(this->name()) + " : enable";
    }

private:
    std::string_view fName;

    using INHERITED = ProgramElement;
};

}  // namespace SkSL

#endif
