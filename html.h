/* -*- c -*- */
/* $Id$ */
#ifndef __HTML_H__
#define __HTML_H__

/* Copyright (C) 2000,2001 Alexander Chernov <cher@ispras.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include <time.h>

void write_standings(char const *, char const *, char const *, char const *);
void write_public_log(char const *, char const *, char const *, char const *);

void new_write_user_runs(FILE *f, int uid, unsigned int show_flags,
                         int sid_mode, unsigned long long sid,
                         unsigned char const *self_url,
                         unsigned char const *hidden_vars);

void new_write_user_clars(FILE *f, int uid, unsigned int show_flags,
                          int sid_mode, unsigned long long sid,
                          unsigned char const *self_url,
                          unsigned char const *hidden_vars);

int new_write_user_clar(FILE *, int, int);
int new_write_user_source_view(FILE *, int, int);
int new_write_user_report_view(FILE *, int, int);

void write_team_page(FILE *f, int user_id,
                     int sid_mode, unsigned long long sid,
                     int all_runs, int all_clars,
                     unsigned char const *self_url,
                     unsigned char const *hidden_vars,
                     time_t server_start,
                     time_t server_end);

void write_master_page(FILE *f,
                       int user_id, int priv_level,
                       int sid_mode, unsigned long long sid,
                       int first_run, int last_run,
                       int first_clar, int last_clar,
                       unsigned char const *self_url,
                       unsigned char const *filter_expr,
                       unsigned char const *hidden_vars);

void write_priv_standings(FILE *f,
                          int sid_mode,
                          unsigned long long sid,
                          unsigned char const *self_url,
                          unsigned char const *hidden_vars);

void write_standings_header(FILE *, int, unsigned char const *);
void do_write_kirov_standings(FILE *, int, unsigned char const *);
void do_write_standings(FILE *, int, unsigned char const *);

int write_priv_source(FILE *f, int user_id, int priv_level,
                      int sid_mode, unsigned long long sid,
                      unsigned char const *self_url,
                      unsigned char const *hidden_vars,
                      int run_id);
int write_priv_report(FILE *f, int user_id, int priv_level,
                      int sid_mode, unsigned long long sid,
                      unsigned char const *self_url,
                      unsigned char const *hidden_vars,
                      int run_id);

int write_priv_clar(FILE *f, int user_id, int priv_level,
                    int sid_mode, unsigned long long sid,
                    unsigned char const *self_url,
                    unsigned char const *hidden_vars,
                    int clar_id);

int write_priv_users(FILE *f, int user_id, int priv_level,
                     int sid_mode, unsigned long long sid,
                     unsigned char const *self_url,
                     unsigned char const *hidden_vars);

void html_start_form(FILE *f, int mode,
                     int sid_mode, unsigned long long sid,
                     unsigned char const *self_url,
                     unsigned char const *hidden_vars);
unsigned char *html_hyperref(unsigned char *buf, int size,
                             int sid_mode, unsigned long long sid,
                             unsigned char const *self_url,
                             unsigned char const *format, ...);

#endif /* __HTML_H__ */
