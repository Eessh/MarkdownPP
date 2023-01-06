#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../termcolor/termcolor.hpp"

namespace Utils {

	enum class ErrorType {
		RUNTIME,
		VALUE,
	};

	class Error {
	public:
		virtual const ErrorType& type() const;

	protected:
		ErrorType mType;
	};

	class RuntimeError: public Error {
	public:
		RuntimeError(const std::string& description);

		const std::string& description() const;
		std::string& description();

	private:
		std::string mDescription;
	};

	class ValueError: public Error {
	public:
		ValueError(const std::string& key, const std::string& expectedValue, const std::string& value);

		const std::string& key() const;
		std::string& key();

		const std::string& expectedValue() const;
		std::string& expectedValue();

		const std::string& value() const;
		std::string& value();

	private:
		std::string mKey;
		std::string mExpectedValue;
		std::string mValue;
	};

	class Test {
	public:
		Test(const std::string& name);
		Test(const std::string& name, const std::string& description);

		const std::string& name() const;
		std::string& name();

		const std::string& description() const;
		std::string& description();

		const std::vector<Error*>& errors() const;
		void addError(Error* error);

		void log() const;

	private:
		std::string mName;
		std::string mDescription;
		std::vector<Error*> mErrors;

		void logPassed() const;
		void logFailed() const;
	};

};


const Utils::ErrorType& Utils::Error::type() const {
	return this->mType;
}

Utils::RuntimeError::RuntimeError(const std::string& description) {
	this->mType = Utils::ErrorType::RUNTIME;
	this->mDescription = description;
}

const std::string& Utils::RuntimeError::description() const {
	return this->mDescription;
}

std::string& Utils::RuntimeError::description() {
	return this->mDescription;
}

Utils::ValueError::ValueError(const std::string& key, const std::string& expectedValue, const std::string& value) {
	this->mType = Utils::ErrorType::VALUE;
	this->mKey = key;
	this->mExpectedValue = expectedValue;
	this->mValue = value;
}

const std::string& Utils::ValueError::key() const {
	return this->mKey;
}

std::string& Utils::ValueError::key() {
	return this->mKey;
}

const std::string& Utils::ValueError::expectedValue() const {
	return this->mExpectedValue;
}

std::string& Utils::ValueError::expectedValue() {
	return this->mExpectedValue;
}

const std::string& Utils::ValueError::value() const {
	return this->mValue;
}

std::string& Utils::ValueError::value() {
	return this->mValue;
}


Utils::Test::Test(const std::string& name)
: mName(name)
{}

Utils::Test::Test(const std::string& name, const std::string& description)
: mName(name), mDescription(description)
{}

const std::string& Utils::Test::name() const {
	return this->mName;
}

std::string& Utils::Test::name() {
	return this->mName;
}

const std::string& Utils::Test::description() const {
	return this->mDescription;
}

std::string& Utils::Test::description() {
	return this->mDescription;
}

const std::vector<Utils::Error*>& Utils::Test::errors() const {
	return this->mErrors;
}

void Utils::Test::addError(Utils::Error* error) {
	this->mErrors.push_back(error);
}

void Utils::Test::log() const {
	if (this->mErrors.empty())
		this->logPassed();
	else
		this->logFailed();
}

void Utils::Test::logPassed() const {
	std::cout << termcolor::on_bright_green << termcolor::bright_white << "Passed" << termcolor::reset << " " << this->mName << "\n";
	std::cout << "Description: " << this->mDescription << "\n";
}

void Utils::Test::logFailed() const {
	std::cout << termcolor::on_bright_red << termcolor::bright_white << "Failed" << termcolor::reset << " " << this->mName << "\n";
	std::cout << "Description: " << this->mDescription << "\n";
	if (this->mErrors.empty())
		return;
	std::cout << termcolor::red << "Errors:\n";
	for (Error* error: this->mErrors) {
		if (error->type() == Utils::ErrorType::RUNTIME) {
			Utils::RuntimeError* rerror = dynamic_cast<Utils::RuntimeError*>(error);
			std::cout << "RuntimeError: " << rerror->description() << "\n";
		}
		else {
			Utils::ValueError* verror = dynamic_cast<Utils::ValueError*>(error);
			std::cout << "Value of " << verror->key() << " does not match with that of expected value:\n";
			std::cout << "  Expected Value: " << verror->expectedValue() << "\n";
			std::cout << "  Returned Value: " << verror->value() << "\n";
		}
	}
	std::cout << termcolor::reset;
}

void Utils__logPassedTest(const std::string& testName, const std::vector<std::string>& errorDesc = {}) {
	std::cout << termcolor::on_bright_green << termcolor::bright_white << "Passed" << termcolor::reset << " " << testName << "\n";
	if (errorDesc.empty())
		return;
	for (const std::string& desc: errorDesc)
		std::cout << termcolor::yellow << desc << termcolor::reset << "\n";
}

void Utils__logFailedTest(const std::string& testName, const std::vector<std::string>& errorDesc = {}) {
	std::cout << termcolor::on_bright_red << termcolor::bright_white << "Failed" << termcolor::reset << " " << testName << "\n";
	if (errorDesc.empty())
		return;
	for (const std::string& desc: errorDesc)
		std::cout << termcolor::red << desc << termcolor::reset << "\n";
}