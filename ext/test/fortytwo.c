
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 * FortyTwo
 */
ZEPHIR_INIT_CLASS(Test_FortyTwo) {

	ZEPHIR_REGISTER_CLASS(Test, FortyTwo, test, fortytwo, test_fortytwo_method_entry, 0);


	return SUCCESS;

}

PHP_METHOD(Test_FortyTwo, proof) {

	zend_function *_10 = NULL;
	zend_class_entry *_9;
	zend_bool _5;
	HashTable *_3;
	HashPosition _2;
	int i, j, _6, _7;
	zval *box, *side = NULL, *_0 = NULL, *_1 = NULL, **_4, *_8;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(box);
	array_init(box);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 10);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 24);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 8);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 8);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 15);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 19);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 19);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 17);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 6);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 6);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 16);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 20);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 20);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 13);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 9);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 9);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 11);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 22);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 22);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 2);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 18);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 18);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 4);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 20);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 5);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 21);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 16);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 16);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 3);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 23);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 23);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 7);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 12);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 12);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 25);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 5);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 24);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 7);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 11);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 11);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 27);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 4);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_0);
	array_init(_0);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 11);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 27);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_LONG(_1, 4);
	zend_hash_next_index_insert(Z_ARRVAL_P(_0), &_1, sizeof(zval *), NULL);
	zend_hash_next_index_insert(Z_ARRVAL_P(box), &_0, sizeof(zval *), NULL);
	zephir_is_iterable(box, &_3, &_2, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(side, _4);
		j = 0;
		_7 = 2;
		_6 = 0;
		_5 = 0;
		if ((_6 <= _7)) {
			while (1) {
				if (_5) {
					_6++;
					if (!((_6 <= _7))) {
						break;
					}
				} else {
					_5 = 1;
				}
				i = _6;
				zephir_array_fetch_long(&_8, side, i, PH_NOISY | PH_READONLY TSRMLS_CC);
				j += zephir_get_numberval(_8);
			}
		}
		if ((j != 42)) {
			ZEPHIR_INIT_NVAR(_0);
			_9 = zend_fetch_class(SL("Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(_0, _9);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "not true", 1);
			zephir_call_method_p1_cache_noret(_0, "__construct", &_10, _1);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

