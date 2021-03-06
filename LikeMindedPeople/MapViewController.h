//
//  MapViewController.h
//  LikeMindedPeople
//
//  Created by Shaun Dowling on 7/30/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "SearchView.h"

typedef enum
{
    fullScreen = 0,
    halfScreen = 1,
    mapHidden = 2
} MapVisible;

@class DataModel, SearchBarPanel, SearchView, SideBar, GeofenceLocation, DetailViewController;
@interface MapViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UIGestureRecognizerDelegate, MKMapViewDelegate, CLLocationManagerDelegate, SearchViewDelegate>
{	
	MKMapView *_mapView;
    MapVisible _mapVisible;
    
	SearchView *_searchView;
	
	UIView *_activityBackgroundView; // A view to show the phone is busy
	UIActivityIndicatorView *_indicatorView;
    
	UIButton *_keyboardCancelButton;

	BOOL _transitioningToFullScreen;	// Used to refresh the annotations because they seem to disapear
	
	NSArray *_searchResults;
	NSMutableArray *_storedResults;		// An array to be used to temporarily store results that have been removed when presenting directions
	
	MKUserLocation *_userLocation;
	
	GeofenceLocation *_refreshLocation;	// The geofence that, if exited, will begin refreshing the geofences
	
	// The button that will be use to remove the slide over view
	UIButton *_slideInCancelButton;
	UIView *_locationDisabledView;

	BOOL _locationSet;
		
	CLLocationManager *_locationManager;
	
	BOOL _askedForPermission;
    
	// Test variables
	BOOL _showingGeofences;
    
	UIView *_debugPanel;
}

@property (nonatomic, strong) IBOutlet MKMapView *mapView;
@property (nonatomic, strong) IBOutlet SearchView *searchView;

@property (nonatomic, strong) IBOutlet UIView *activityBackgroundView;
@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *indicatorView;

@property (nonatomic, strong) IBOutlet UIView *locationDisabledView;
@property (nonatomic, strong) IBOutlet UIView *debugPanel;

@property (nonatomic) MapVisible mapVisible;

- (IBAction)enableLocationServices;

- (IBAction)printCurrentCenter;
- (IBAction)currentLocation;
- (IBAction)displayGeofences;

- (IBAction)refreshLocation;
- (IBAction)showDetailView;

@end
