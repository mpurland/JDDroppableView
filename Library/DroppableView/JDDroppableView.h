//
//  JDDroppableView.h
//  JDDroppableView
//
//  Created by Markus Emrich on 01.07.10.
//  Copyright 2010 Markus Emrich. All rights reserved.
//


@protocol JDDroppableViewDelegate;

@interface JDDroppableView : UIView {
    CGPoint initialPoint;
    BOOL dragging;
}

@property (nonatomic, weak) id<JDDroppableViewDelegate> delegate;

@property (nonatomic, assign) CGPoint returnPosition;
@property (nonatomic, assign) BOOL shouldUpdateReturnPosition;
@property (nonatomic, assign) BOOL shouldUpdateX;
@property (nonatomic, assign) BOOL shouldUpdateY;
@property (nonatomic, assign) BOOL shouldUseLimits;
@property (nonatomic, assign) CGFloat limitMinX;
@property (nonatomic, assign) CGFloat limitMaxX;
@property (nonatomic, assign) CGFloat limitMinY;
@property (nonatomic, assign) CGFloat limitMaxY;

- (id)initWithDropTarget:(UIView*)target;

// target managment
- (void)addDropTarget:(UIView*)target;
- (void)removeDropTarget:(UIView*)target;
- (void)replaceDropTargets:(NSArray*)targets;

@end


// JDDroppableViewDelegate

@protocol JDDroppableViewDelegate <NSObject>
@optional
// track dragging state
- (void)droppableViewBeganDragging:(JDDroppableView*)view;
- (void)droppableViewDidMove:(JDDroppableView*)view;
- (void)droppableViewEndedDragging:(JDDroppableView*)view onTarget:(UIView*)target;

// track target recognition
- (void)droppableView:(JDDroppableView*)view enteredTarget:(UIView*)target;
- (void)droppableView:(JDDroppableView*)view leftTarget:(UIView*)target;
- (BOOL)shouldAnimateDroppableViewBack:(JDDroppableView*)view wasDroppedOnTarget:(UIView*)target;
@end