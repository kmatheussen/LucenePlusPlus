/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BaseTokenStreamFixture.h"
#include "ArabicStemFilter.h"
#include "ArabicLetterTokenizer.h"
#include "StringReader.h"

using namespace Lucene;

class ArabicStemFilterFixture : public BaseTokenStreamFixture
{
public:
	virtual ~ArabicStemFilterFixture()
	{
	}

public:
	void check(const String& input, const String& expected)
    {
        ArabicLetterTokenizerPtr tokenStream  = newLucene<ArabicLetterTokenizer>(newLucene<StringReader>(input));
        ArabicStemFilterPtr filter = newLucene<ArabicStemFilter>(tokenStream);
        checkTokenStreamContents(filter, newCollection<String>(expected));
    }
};

BOOST_FIXTURE_TEST_SUITE(ArabicStemFilterTest, ArabicStemFilterFixture)

BOOST_AUTO_TEST_CASE(testAlPrefix)
{
    const uint8_t first[] = {0xd8, 0xa7, 0xd9, 0x84, 0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testWalPrefix)
{
    const uint8_t first[] = {0xd9, 0x88, 0xd8, 0xa7, 0xd9, 0x84, 0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testBalPrefix)
{
    const uint8_t first[] = {0xd8, 0xa8, 0xd8, 0xa7, 0xd9, 0x84, 0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testKalPrefix)
{
    const uint8_t first[] = {0xd9, 0x83, 0xd8, 0xa7, 0xd9, 0x84, 0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testFalPrefix)
{
    const uint8_t first[] = {0xd9, 0x81, 0xd8, 0xa7, 0xd9, 0x84, 0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testLlPrefix)
{
    const uint8_t first[] = {0xd9, 0x84, 0xd9, 0x84, 0xd8, 0xa7, 0xd8, 0xae, 0xd8, 0xb1};
    const uint8_t second[] = {0xd8, 0xa7, 0xd8, 0xae, 0xd8, 0xb1};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testWaPrefix)
{
    const uint8_t first[] = {0xd9, 0x88, 0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xad, 0xd8, 0xb3, 0xd9, 0x86};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testAhSuffix)
{
    const uint8_t first[] = {0xd8, 0xb2, 0xd9, 0x88, 0xd8, 0xac, 0xd9, 0x87, 0xd8, 0xa7};
    const uint8_t second[] = {0xd8, 0xb2, 0xd9, 0x88, 0xd8, 0xac};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testAnSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd8, 0xa7, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testAtSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd8, 0xa7, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testWnSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd9, 0x88, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testYnSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd9, 0x8a, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testYhSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd9, 0x8a, 0xd9, 0x87};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testYpSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd9, 0x8a, 0xd8, 0xa9};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testHSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd9, 0x87};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testPSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd8, 0xa9};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testYSuffix)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd9, 0x8a};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testComboPrefSuf)
{
    const uint8_t first[] = {0xd9, 0x88, 0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd9, 0x88, 0xd9, 0x86};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testComboSuf)
{
    const uint8_t first[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf, 0xd9, 0x87, 0xd8, 0xa7, 0xd8, 0xaa};
    const uint8_t second[] = {0xd8, 0xb3, 0xd8, 0xa7, 0xd9, 0x87, 0xd8, 0xaf};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testShouldntStem)
{
    const uint8_t first[] = {0xd8, 0xa7, 0xd9, 0x84, 0xd9, 0x88};
    const uint8_t second[] = {0xd8, 0xa7, 0xd9, 0x84, 0xd9, 0x88};
    check(StringUtils::toUnicode(first, sizeof(first) / sizeof(first[0])), StringUtils::toUnicode(second, sizeof(second) / sizeof(second[0])));
}

BOOST_AUTO_TEST_CASE(testNonArabic)
{
    check(L"English", L"English");
}

BOOST_AUTO_TEST_SUITE_END()