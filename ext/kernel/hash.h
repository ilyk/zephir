
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Zephir Team  (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                      |
  |          Eduar Carvajal <eduar@zephir-lang.com>                         |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_HASH_H
#define ZEPHIR_KERNEL_HASH_H

int zephir_hash_exists(const HashTable *ht, const char *arKey, uint nKeyLength);
int zephir_hash_quick_exists(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h);
int zephir_hash_find(const HashTable *ht, const char *arKey, uint nKeyLength, void **pData);
int zephir_hash_quick_find(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h, void **pData);
void zephir_get_current_key(zval **key, const HashTable *hash_table, HashPosition *hash_position TSRMLS_DC);
zval zephir_get_current_key_w(const HashTable *hash_table, HashPosition *hash_position);
int zephir_has_numeric_keys(const zval *data);
void zephir_hash_update_or_insert(HashTable *ht, zval *offset, zval *value);
zval** zephir_hash_get(HashTable *ht, zval *key, int type);
int zephir_hash_unset(HashTable *ht, zval *offset);

#endif