/*
 * Copyright (c) 2021, Luke Wilde <lukew@serenityos.org>
 * Copyright (c) 2022, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Bindings/PlatformObject.h>
#include <LibWeb/WebIDL/ExceptionOr.h>

namespace Web::HTML {

class History final : public Bindings::PlatformObject {
    WEB_PLATFORM_OBJECT(History, Bindings::PlatformObject);

public:
    static JS::NonnullGCPtr<History> create(JS::Realm&, DOM::Document&);

    virtual ~History() override;

    WebIDL::ExceptionOr<void> push_state(JS::Value data, String const& unused, String const& url);
    WebIDL::ExceptionOr<void> replace_state(JS::Value data, String const& unused, String const& url);

private:
    History(JS::Realm&, DOM::Document&);

    virtual void visit_edges(Cell::Visitor&) override;

    enum class IsPush {
        No,
        Yes,
    };
    WebIDL::ExceptionOr<void> shared_history_push_replace_state(JS::Value data, String const& url, IsPush is_push);

    JS::NonnullGCPtr<DOM::Document> m_associated_document;
};

}
