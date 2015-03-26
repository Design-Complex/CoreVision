%% CoreVision.m
%%
%% Initialize the CoreVision environment..
%%
%% usage: CV = CoreVision( immediate | program );

classdef ( ConstructOnLoad = true, Sealed = true ) CoreVision < handle
    % Constants
    properties ( Constant )
       
        version = 1.0;
        
    end
    
    % Properties
    properties
        mode = 'immediate'
    end
    
    % Methods
    methods
        
        % Constructor
        function CV = CoreVision( mode )
            switch( mode )
                case 'program'
                    CV.mode = 'program';
                case 'immediate'
                    
                otherwise
                    CoreVision.usage();
                    error( 'Invalid mode.\n' );
            end
            
        end
        
    end
    
    % Static Methods
    methods ( Static, Hidden )
    
        function usage()
            display 'usage: CV = CoreVision( 'immediate' | 'program' );'
        end
        
    end
    
    % Events
    events
        
    end
    
end
    
    