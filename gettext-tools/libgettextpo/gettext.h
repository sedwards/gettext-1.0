#ifndef _GETTEXT_H
#define _GETTEXT_H
#include <string.h>
#define _(msgid) (msgid)
#define gettext(msgid) (msgid)
#define dgettext(domain, msgid) (msgid)
#define dcgettext(domain, msgid, category) (msgid)
#define ngettext(msgid1, msgid2, n) ((n) == 1 ? (msgid1) : (msgid2))
#define dngettext(domain, msgid1, msgid2, n) ((n) == 1 ? (msgid1) : (msgid2))
#define dcngettext(domain, msgid1, msgid2, n, category) ((n) == 1 ? (msgid1) : (msgid2))
#endif
