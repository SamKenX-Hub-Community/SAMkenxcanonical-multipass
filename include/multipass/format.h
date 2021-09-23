/*
 * Copyright (C) 2019-2022 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_FORMAT_H
#define MULTIPASS_FORMAT_H

#include <fmt/format.h>
#include <fmt/ostream.h>

#include <filesystem>

#include <QByteArray>
#include <QString>

namespace fmt
{
template <>
struct formatter<QByteArray>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const QByteArray& a, FormatContext& ctx)
    {
        return format_to(ctx.out(), "{}", a.toStdString()); // TODO: remove the copy?
    }
};

template <>
struct formatter<QString>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const QString& a, FormatContext& ctx)
    {
        return format_to(ctx.out(), "{}", a.toStdString()); // TODO: remove the copy?
    }
};

// TODO this will be included in fmtlib v9
template <>
struct formatter<std::filesystem::path>
{
    template <typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const std::filesystem::path& path, FormatContext& ctx)
    {
        return format_to(ctx.out(), "'{}'", path.string());
    }
};

} // namespace fmt

#endif // MULTIPASS_FORMAT_H
