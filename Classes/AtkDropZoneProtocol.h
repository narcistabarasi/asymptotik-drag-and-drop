//
//  AtkDropZoneProtocol.h
//  Rnd_DragAndDrop
//
//  Created by Rick Boykin on 1/17/14.
//  Copyright (c) 2014 Mondo Robot. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AtkDragAndDropManager;

@protocol AtkDropZoneProtocol <NSObject>

@optional

- (BOOL)isActive:(AtkDragAndDropManager *)manager point:(CGPoint)point;

/**
 * A drag has started and dragStarted returned YES. Should we consider this drop zone interested in receiving
 * the following calls dragStarted, dragEntered, dragExited, dragMoved, dragDropped and dragEnded.
 */
- (BOOL)isInterested:(AtkDragAndDropManager *)manager;

/**
 * A drag has started, should we consider this drop zone. A drop zone that is considered
 * will receive calls, as appropriate, to isInterested and dragEnded but not dragStarted, 
 * dragEntered, dragExited, dragMoved and dragDropped
 */
- (BOOL)shouldDragStart:(AtkDragAndDropManager *)manager;

/*
 * called on all drop zones that responded YES to dragStarted when the drag operation has started. This will
 * be soon after shouldDragStart responds YES.
 */
- (void)dragStarted:(AtkDragAndDropManager *)manager;

/*
 * called on all drop zones that responded YES to dragStarted when the drag operation has ended. This will
 * be called last in the lifecycle of AtkDragAndDrop.
 */
- (void)dragEnded:(AtkDragAndDropManager *)manager;

/*
 * Called when the drag has entered the drop zone.
 */
- (void)dragEntered:(AtkDragAndDropManager *)manager point:(CGPoint)point;

/*
 * Called when the drag has exited the drop zone.
 */
- (void)dragExited:(AtkDragAndDropManager *)manager point:(CGPoint)point;

/*
 * Called when the drag is in the drop zone and has moved.
 */
- (void)dragMoved:(AtkDragAndDropManager *)manager point:(CGPoint)point;

/*
 * called when the drag is in the drop zone and has been dropped.
 */
- (void)dragDropped:(AtkDragAndDropManager *)manager point:(CGPoint)point;

@end
