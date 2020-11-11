import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;

public class BinarySearch
{
    public static int[] to_search;

    public static void main( String[] args)
    {
        BinarySearch binary_search = new BinarySearch();
        int to_find = 0;
        int to_search_size = 0;

        if (args.length > 0)
        {
            try 
            {
                to_find = Integer.parseInt(args[0]);
            } 
            catch (NumberFormatException e) 
            {
                System.err.println("Argument"+args[0]+" must be an integer.");
                System.exit(1);
            }
            try 
            {
                to_search_size = Integer.parseInt(args[1]);
            } 
            catch (NumberFormatException e) 
            {
                System.err.println("Argument"+args[0]+" must be an integer.");
                System.exit(1);
            }
        }

        to_search = new int[to_search_size];
        binary_search.readFile( args[2] ); 

        int is_found =  binary_search.searchArray( to_find );

        if ( is_found == -1 )
        {
            System.out.println( to_find + " is not in the supplied list" );
        }
        else
        {
            System.out.println( to_find + " is in the list, and has possition: " + is_found );
        }
    }

    private BinarySearch()
    {
    }

    private void readFile( String file_name )
    {
        try
        {
            Scanner file_scanner = new Scanner( new File( file_name ) );
            int iter = 0;
            while ( file_scanner.hasNextInt() )
            {
                to_search[iter] = file_scanner.nextInt();
                iter++;
            }
        }
        catch ( FileNotFoundException e )
        {
            System.err.println( "FileNotFoundException: " + e.getMessage() );
        }
    }

    private int searchArray( int to_find )
    {
        
        int low  = 0;
        int high = to_search.length - 1;

        while ( low <= high )
        {

            int mid  = low + (high-low)/2;

            if ( to_search[mid] > to_find )
            {
                high = mid - 1;
            }
            else if ( to_search[mid] < to_find )
            {
                low = mid + 1;
                
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
}
