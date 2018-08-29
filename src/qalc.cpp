// rofi-qalc: A qalculator plugin for rofi
// Copyright (C) 2018 <tomKPZ@gmail.com>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA

#include <rofi/mode.h>

// TODO: Sort includes once the below change lands:
// https://github.com/DaveDavenport/rofi/pull/848
#include <rofi/mode-private.h>

#include <libqalculate/Calculator.h>
#include <iostream>
#include <memory>
#include <string>

namespace {

typedef struct {
  std::string result;
} QalcPrivateData;

QalcPrivateData* get_private_data(const Mode* sw) {
  return reinterpret_cast<QalcPrivateData*>(mode_get_private_data(sw));
}

int qalc_mode_init(Mode* sw) {
  QalcPrivateData* pd = get_private_data(sw);
  if (!pd) {
    pd = new QalcPrivateData();
    mode_set_private_data(sw, reinterpret_cast<void*>(pd));
  }
  return true;
}

void qalc_mode_destroy(Mode* sw) {
  QalcPrivateData* pd = get_private_data(sw);
  if (pd) {
    delete pd;
    mode_set_private_data(sw, nullptr);
  }
}

unsigned int qalc_mode_get_num_entries(const Mode* sw) {
  return 1;
}

ModeMode qalc_mode_result(Mode* sw,
                          int menu_entry,
                          char** input,
                          unsigned int selected_line) {
  return MODE_EXIT;
}

int qalc_token_match(const Mode* sw,
                     rofi_int_matcher** tokens,
                     unsigned int index) {
  return 1;
}

char* qalc_get_display_value(const Mode* sw,
                             unsigned int selected_line,
                             int* state,
                             GList** attr_list,
                             int get_entry) {
  return strdup(get_private_data(sw)->result.c_str());
}

char* qalc_preprocess_input(Mode* sw, const char* input) {
  std::unique_ptr<Calculator> calculator = std::make_unique<Calculator>();
  calculator->loadGlobalDefinitions();
  calculator->loadLocalDefinitions();
  get_private_data(sw)->result = calculator->calculateAndPrint(input, 250);
  return strdup(input);
}

char* qalc_get_message(const Mode* sw) {
  return nullptr;
}

}  // namespace

Mode mode{
    ABI_VERSION,
    const_cast<char*>(&"qalc"[0]),
    "",
    const_cast<char*>(&"qalc"[0]),
    qalc_mode_init,
    qalc_mode_destroy,
    qalc_mode_get_num_entries,
    qalc_mode_result,
    qalc_token_match,
    qalc_get_display_value,
    nullptr,
    nullptr,
    qalc_preprocess_input,
    qalc_get_message,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
