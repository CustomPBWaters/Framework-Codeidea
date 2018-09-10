/*
 * UICollisionBehavior.h
 *
 * UIKit (c) 2012-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIBezierPath.h>
#import <UIKit/UIDynamicBehavior.h>

NS_ASSUME_NONNULL_BEGIN

@class UICollisionBehavior;

typedef NS_OPTIONS(NSUInteger, UICollisionBehaviorMode) {
    UICollisionBehaviorModeItems        = 1 << 0,
    UICollisionBehaviorModeBoundaries   = 1 << 1,
    UICollisionBehaviorModeEverything   = NSUIntegerMax
} NS_ENUM_AVAILABLE_IOS(7_0);

@protocol UICollisionBehaviorDelegate <NSObject>
@optional

- (void)collisionBehavior:(UICollisionBehavior *)behavior beganContactForItem:(id <UIDynamicItem>)item1 withItem:(id <UIDynamicItem>)item2 atPoint:(CGPoint)p;
- (void)collisionBehavior:(UICollisionBehavior *)behavior endedContactForItem:(id <UIDynamicItem>)item1 withItem:(id <UIDynamicItem>)item2;

// The identifier of a boundary created with translatesReferenceBoundsIntoBoundary or setTranslatesReferenceBoundsIntoBoundaryWithInsets is nil
- (void)collisionBehavior:(UICollisionBehavior*)behavior beganContactForItem:(id <UIDynamicItem>)item withBoundaryIdentifier:(nullable id <NSCopying>)identifier atPoint:(CGPoint)p;
- (void)collisionBehavior:(UICollisionBehavior*)behavior endedContactForItem:(id <UIDynamicItem>)item withBoundaryIdentifier:(nullable id <NSCopying>)identifier;

@end


NS_CLASS_AVAILABLE_IOS(7_0) @interface UICollisionBehavior : UIDynamicBehavior

- (instancetype)initWithItems:(NSArray<id <UIDynamicItem>> *)items NS_DESIGNATED_INITIALIZER;

- (void)addItem:(id <UIDynamicItem>)item;
- (void)removeItem:(id <UIDynamicItem>)item;

@property (nonatomic, readonly, copy) NSArray<id <UIDynamicItem>> *items;

@property (nonatomic, readwrite) UICollisionBehaviorMode collisionMode;

@property (nonatomic, readwrite) BOOL translatesReferenceBoundsIntoBoundary;
- (void)setTranslatesReferenceBoundsIntoBoundaryWithInsets:(UIEdgeInsets)insets;

- (void)addBoundaryWithIdentifier:(id <NSCopying>)identifier forPath:(UIBezierPath *)bezierPath;
- (void)addBoundaryWithIdentifier:(id <NSCopying>)identifier fromPoint:(CGPoint)p1 toPoint:(CGPoint)p2;
- (nullable UIBezierPath *)boundaryWithIdentifier:(id <NSCopying>)identifier;
- (void)removeBoundaryWithIdentifier:(id <NSCopying>)identifier;
@property (nullable, nonatomic, readonly, copy) NSArray<id <NSCopying>> *boundaryIdentifiers;
- (void)removeAllBoundaries;

@property (nullable, nonatomic, weak, readwrite) id <UICollisionBehaviorDelegate> collisionDelegate;

@end

NS_ASSUME_NONNULL_END

