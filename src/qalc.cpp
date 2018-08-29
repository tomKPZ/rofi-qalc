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

#include <rofi/helper.h>
#include <rofi/mode-private.h>
#include <rofi/mode.h>

#include <rofi/mode.h>
#include <rofi/rofi-icon-fetcher.h>

namespace {

typedef struct {
} CALCModePrivateData;

int qalc_mode_init(Mode* sw) {
  if (mode_get_private_data(sw) == nullptr) {
    CALCModePrivateData* pd = new CALCModePrivateData();
    mode_set_private_data(sw, (void*)pd);
  }
  return true;
}

void qalc_mode_destroy(Mode* sw) {
  CALCModePrivateData* pd = (CALCModePrivateData*)mode_get_private_data(sw);
  if (pd != nullptr) {
    delete pd;
    mode_set_private_data(sw, nullptr);
  }
}

unsigned int qalc_mode_get_num_entries(const Mode* sw) {
  return 0;
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
  return true;
}

char* qalc_get_display_value(const Mode* sw,
                             unsigned int selected_line,
                             int* state,
                             GList** attr_list,
                             int get_entry) {
  return nullptr;
}

char* qalc_preprocess_input(Mode* sw, const char* input) {
  return nullptr;
}

char* qalc_get_message(const Mode* sw) {
  return nullptr;
}

}  // namespace

Mode mode{
    ABI_VERSION,
    const_cast<char*>(&"qalc"[0]),
    "",
    const_cast<char*>(&"display-qalc"[0]),
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
