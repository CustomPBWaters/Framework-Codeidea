/*
 * NSText.h
 *
 * UIKit (c) 2011-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */
 

#import <Foundation/Foundation.h>
#if __has_include(<CoreText/CTParagraphStyle.h>)
#import <CoreText/CTParagraphStyle.h>
#endif
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

/* Values for NSTextAlignment */
typedef NS_ENUM(NSInteger, NSTextAlignment) {
    NSTextAlignmentLeft      = 0,    // Visually left aligned
#if TARGET_OS_IPHONE
    NSTextAlignmentCenter    = 1,    // Visually centered
    NSTextAlignmentRight     = 2,    // Visually right aligned
#else /* !TARGET_OS_IPHONE */
    NSTextAlignmentRight     = 1,    // Visually right aligned
    NSTextAlignmentCenter    = 2,    // Visually centered
#endif
    NSTextAlignmentJustified = 3,    // Fully-justified. The last line in a paragraph is natural-aligned.
    NSTextAlignmentNatural   = 4,    // Indicates the default alignment for script
} NS_ENUM_AVAILABLE_IOS(6_0);

#if __has_include(<CoreText/CTParagraphStyle.h>)
UIKIT_EXTERN CTTextAlignment NSTextAlignmentToCTTextAlignment(NSTextAlignment nsTextAlignment) NS_AVAILABLE_IOS(6_0);
UIKIT_EXTERN NSTextAlignment NSTextAlignmentFromCTTextAlignment(CTTextAlignment ctTextAlignment) NS_AVAILABLE_IOS(6_0);
#endif

/* Values for NSWritingDirection */
typedef NS_ENUM(NSInteger, NSWritingDirection) {
    NSWritingDirectionNatural       = -1,    // Determines direction using the Unicode Bidi Algorithm rules P2 and P3
    NSWritingDirectionLeftToRight   =  0,    // Left to right writing direction
    NSWritingDirectionRightToLeft   =  1     // Right to left writing direction
} NS_ENUM_AVAILABLE_IOS(6_0);

NS_ASSUME_NONNULL_END

