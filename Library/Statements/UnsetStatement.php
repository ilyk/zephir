<?php

/*
 +----------------------------------------------------------------------+
 | Zephir Language                                                      |
 +----------------------------------------------------------------------+
 | Copyright (c) 2013 Zephir Team                                       |
 +----------------------------------------------------------------------+
 | This source file is subject to version 1.0 of the Zephir license,    |
 | that is bundled with this package in the file LICENSE, and is        |
 | available through the world-wide-web at the following url:           |
 | http://www.zephir-lang.com/license                                   |
 |                                                                      |
 | If you did not receive a copy of the Zephir license and are unable   |
 | to obtain it through the world-wide-web, please send a note to       |
 | license@zephir-lang.com so we can mail you a copy immediately.       |
 +----------------------------------------------------------------------+
*/

/**
 * UnsetStatement
 *
 * Unset statement
 */
class UnsetStatement
{
	protected $_statement;

	public function __construct($statement)
	{
		$this->_statement = $statement;
	}

	/**
	 * @param \CompilationContext $compilationContext
	 */
	public function compile(CompilationContext $compilationContext)
	{
		$compilationContext->headersManager->add('kernel/array');

		$variable = $compilationContext->symbolTable->getVariableForWrite($this->_statement['domain']['value'], $compilationContext, $this->_statement);
		if ($variable->getType() != 'variable') {
			throw new CompilerException('Cannot use variable type: ' . $variable->gettype() . ' in "unset"', $this->_statement['domain']);
		}

		$expr = new Expression($this->_statement['index']);
		$expr->setReadOnly(true);
		$exprIndex = $expr->compile($compilationContext);

		$flags = 'PH_SEPARATE';

		switch ($exprIndex->getType()) {
			case 'string':
				$compilationContext->codePrinter->output('zephir_array_unset_string(&' . $variable->getName() . ', SS("' . $exprIndex->getCode() . '"), ' . $flags . ');');
				break;
			case 'long':
				break;
			case 'variable':
				$variableIndex = $compilationContext->symbolTable->getVariableForRead($exprIndex->getCode(), $compilationContext, $this->_statement['index']);
				switch ($variableIndex->getType()) {
					case 'int':
					case 'uint':
					case 'long':
						$compilationContext->headersManager->add('kernel/array');
						$compilationContext->codePrinter->output('zephir_array_unset_string(&' . $variable->getName() . ', ' . $variableIndex->getName() . ', ' . $flags . ' TSRMLS_CC);');
						break;
					case 'string':
					case 'variable':
						$compilationContext->headersManager->add('kernel/array');
						$compilationContext->codePrinter->output('zephir_array_unset(&' . $variable->getName() . ', ' . $variableIndex->getName() . ', ' . $flags . ' TSRMLS_CC);');
						break;
					default:
						throw new CompilerException("Variable type: " . $variableIndex->getType() . " cannot be used as array index without cast", $this->_statement['index']);
				}
				break;
			default:
				throw new CompilerException("Cannot use expression: " . $exprIndex->getType() . " as array index without cast", $this->_statement['index']);
		}
	}

}
