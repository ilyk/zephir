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
 * ClassProperty
 *
 * Represents a property class
 */
class ClassProperty
{

	protected $_visibility;

	protected $_name;

	protected $defaultValue;

	protected $_docblock;

	protected $_original;

	/**
	 *
	 *
	 * @param array $visibility
	 * @param string $name
	 * @param mixed $defaultValue
	 * @param string $docBlock
	 * @param array $original
	 */
	public function __construct($visibility, $name, $defaultValue, $docBlock, $original)
	{

		$this->checkVisibility($visibility, $name, $original);

		$this->_visibility = $visibility;
		$this->_name = $name;
		$this->_defaultValue = $defaultValue;
		$this->_docblock = $docBlock;
		$this->_original = $original;
	}

	/**
	 * Returns the property name
	 *
	 * @return string
	 */
	public function getName()
	{
		return $this->_name;
	}

	public function getOriginal()
	{
		return $this->_original;
	}

	/**
	 * Checks for visibility congruence
	 *
	 * @param array $visibility
	 * @param string $name
	 * @param array $original
	 */
	public function checkVisibility($visibility, $name, $original)
	{
		if (in_array('public', $visibility) && in_array('protected', $visibility)) {
			throw new CompilerException("Property '$name' cannot be 'public' and 'protected' at the same time", $original);
		}
		if (in_array('public', $visibility) && in_array('private', $visibility)) {
			throw new CompilerException("Property '$name' cannot be 'public' and 'private' at the same time", $original);
		}
		if (in_array('private', $visibility) && in_array('protected', $visibility)) {
			throw new CompilerException("Property '$name' cannot be 'protected' and 'private' at the same time", $original);
		}
	}

	/**
	 * Returns the C-visibility accesors for the model
	 *
	 * @return string
	 */
	public function getVisibilityAccesor()
	{
		$modifiers = array();
		foreach ($this->_visibility as $visibility) {
			switch ($visibility) {
				case 'protected':
					$modifiers['ZEND_ACC_PROTECTED'] = true;
					break;
				case 'private':
					$modifiers['ZEND_ACC_PRIVATE'] = true;
					break;
				case 'public':
					$modifiers['ZEND_ACC_PUBLIC'] = true;
					break;
				case 'static':
					$modifiers['ZEND_ACC_STATIC'] = true;
					break;
				default:
					throw new Exception("Unknown modifier " . $visibility);

			}
		}
		return join('|', array_keys($modifiers));
	}

	/**
	 * Returns the docblock related to the property
	 *
	 * @return string
	 */
	public function getDocBlock()
	{
		return $this->_docblock;
	}

	/**
	 * Checks whether the variable is static
	 *
	 * @return boolean
	 */
	public function isStatic()
	{
		return in_array('static', $this->_visibility);
	}

	/**
	 * Checks whether the variable is public
	 *
	 * @return boolean
	 */
	public function isPublic()
	{
		return in_array('public', $this->_visibility);
	}

	/**
	 * Checks whether the variable is protected
	 *
	 * @return boolean
	 */
	public function isProtected()
	{
		return in_array('protected', $this->_visibility);
	}

	/**
	 * Checks whether the variable is private
	 *
	 * @return boolean
	 */
	public function isPrivate()
	{
		return in_array('private', $this->_visibility);
	}

	/**
	 * Produce the code to register a property
	 *
	 * @param CompilationContext $compilationContext
	 */
	public function compile(CompilationContext $compilationContext)
	{

		if (!is_array($this->_defaultValue)) {
			$compilationContext->codePrinter->output("zend_declare_property_null(" .
				$compilationContext->classDefinition->getClassEntry() .
				", SL(\"" . $this->getName() . "\"), " .
				$this->getVisibilityAccesor() . " TSRMLS_CC);");
		} else {
			switch ($this->_defaultValue['type']) {
				case 'long':
				case 'int':
					$compilationContext->codePrinter->output("zend_declare_property_long(" .
						$compilationContext->classDefinition->getClassEntry() .
						", SL(\"" . $this->getName() . "\"), " . $this->_defaultValue['value'] . ", " .
						$this->getVisibilityAccesor() . " TSRMLS_CC);");
					break;
				case 'double':
					$compilationContext->codePrinter->output("zend_declare_property_double(" .
						$compilationContext->classDefinition->getClassEntry() .
						", SL(\"" . $this->getName() . "\"), " . $this->_defaultValue['value'] . ", " .
						$this->getVisibilityAccesor() . " TSRMLS_CC);");
					break;
				case 'bool':
					if ($this->_defaultValue['value'] == 'false') {
						$compilationContext->codePrinter->output("zend_declare_property_bool(" .
							$compilationContext->classDefinition->getClassEntry() .
							", SL(\"" . $this->getName() . "\"), 0, " .
							$this->getVisibilityAccesor() . " TSRMLS_CC);");
					} else {
						$compilationContext->codePrinter->output("zend_declare_property_bool(" .
							$compilationContext->classDefinition->getClassEntry() .
							", SL(\"" . $this->getName() . "\"), 1, " .
							$this->getVisibilityAccesor() . " TSRMLS_CC);");
					}
					break;
				case 'string':
					$compilationContext->codePrinter->output("zend_declare_property_string(" .
						$compilationContext->classDefinition->getClassEntry() .
						", SL(\"" . $this->getName() . "\"), \"" . Utils::addSlaches($this->_defaultValue['value']) . "\", " .
						$this->getVisibilityAccesor() . " TSRMLS_CC);");
					break;
				default:
					$compilationContext->codePrinter->output("zend_declare_property_null(" .
						$compilationContext->classDefinition->getClassEntry() .
						", SL(\"" . $this->getName() . "\"), " .
						$this->getVisibilityAccesor() . " TSRMLS_CC);");
			}
		}
	}

}
